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
  u64 x, y, m;
  cin >> x >> y >> m;

  u64 ans = 0;
  for (u32 x_uses = 0; x_uses <= m / x; ++x_uses) {
    for (u32 y_uses = 0; y_uses <= (m - x_uses * x) / y; ++y_uses) {
      u64 used = x_uses * x + y_uses * y;
      ans = max(ans, used);
    }
  }

  cout << ans << '\n';
}

int main() { // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

#define PROBLEM_NAME "pails"

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
