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

void solve() {
  u32 n;
  cin >> n;
  vector<u64> a(n);
  for (auto &e : a)
    cin >> e;

  u64 big = *max_element(all(a));
  u64 ub = accumulate(all(a), 0LL);

  for (u64 target = big; target <= ub; ++target) {
    u32 last = 0, moves = 0;
    u64 total = 0;
    bool bad = false;
    for (u32 i = 0; i < n && !bad; ++i) {
      total += a[i];
      if (total == target) {
        moves += i - last;
        last = i + 1;
        total = 0;
      } else if (i == n - 1 && total != target || total > target) {
        bad = true;
      }
    }
    if (!bad) {
      cout << moves + n - last << endl;
      return;
    }
  }
}

int main() { // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

#define PROBLEM_NAME "sleeping-in-class"

#ifdef LOCAL
  freopen("io/" PROBLEM_NAME ".in", "r", stdin);
  freopen("io/" PROBLEM_NAME ".out", "w", stdout);
#endif

  u32 t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
// }}}
