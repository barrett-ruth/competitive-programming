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
  i32 n;
  cin >> n;
  vector<i32> a(n);
  for (auto &e : a)
    cin >> e;
  sort(all(a));

  i32 ans = 1;
  for (u32 i = 0; i < n; ++i) {
    i32 l = i;
    i32 radius = 1;

    while (l >= 0) {
      i32 j = l;
      while (j >= 0 && a[j] >= a[l] - radius) {
        --j;
      }
      ++j;
      if (j == l) {
        break;
      }
      l = j;
      ++radius;
    }

    i32 r = i;
    radius = 1;
    while (r < n) {
      i32 j = r;
      while (j < n && a[j] <= a[r] + radius) {
        ++j;
      }
      --j;
      if (j == r) {
        break;
      }
      ++radius;
      r = j;
    }

    ans = max(ans, r - l + 1);
  }
  cout << ans << '\n';
}

int main() { // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

#define PROBLEM_NAME "angry"

#ifdef LOCAL
  freopen("io/" PROBLEM_NAME ".in", "r", stdin);
  freopen("io/" PROBLEM_NAME ".out", "w", stdout);
#else
  freopen(PROBLEM_NAME ".in", "r", stdin);
  freopen(PROBLEM_NAME ".out", "w", stdout);
#endif

  solve();

  return 0;
}
// }}}
