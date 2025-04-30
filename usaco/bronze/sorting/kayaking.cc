#include <bits/stdc++.h> // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
using f128 = long double;

#if __cplusplus >= 202002L
template <typename T> constexpr T MIN = std::numeric_limits<T>::min();

template <typename T> constexpr T MAX = std::numeric_limits<T>::max();

template <typename T> [[nodiscard]] static T sc(auto &&x) {
  return static_cast<T>(x);
}

template <typename T> [[nodiscard]] static T sz(auto &&x) {
  return static_cast<T>(x.size());
}
#endif

static void NO() { std::cout << "NO\n"; }

static void YES() { std::cout << "YES\n"; }

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second

#ifdef LOCAL
#define db(...) std::print(__VA_ARGS__)
#define dbln(...) std::println(__VA_ARGS__)
#else
#define db(...)
#define dbln(...)
#endif
//  }}}

long long findMinScore(std::vector<int> &a) {
  int n = a.size() / 2;
  long long S = 0;
  for (int i = 0; i < 2 * n; i += 2) {
    S += a[i + 1] - a[i];
  }
  long long min_score = S;
  for (int i = 0; i < 2 * n - 1; i++) {
    long long diff = a[i + 1] - a[i];
    long long score = (i % 2 == 0) ? S - diff : S + diff;
    min_score = std::min(min_score, score);
  }
  long long adjust = a[1] - a[0];
  for (int k = 1; k < n; k++) {
    adjust += a[2 * k + 1] - 2LL * a[2 * k] + a[2 * k - 1];
  }
  min_score = std::min(min_score, S - adjust);
  return min_score;
}

void solve() {
  u32 n;
  cin >> n;
  vector<i32> a(n * 2);
  for (auto &e : a)
    cin >> e;
  sort(all(a));

  cout << findMinScore(a);
}

int main() { // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  u32 tc = 1;
  // cin >> tc;

  for (u32 t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
