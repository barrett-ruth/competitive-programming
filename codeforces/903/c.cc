#include <bits/stdc++.h>  // {{{

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
template <typename T>
constexpr T MIN = std::numeric_limits<T>::min();

template <typename T>
constexpr T MAX = std::numeric_limits<T>::max();

template <typename T>
[[nodiscard]] static T sc(auto&& x) {
  return static_cast<T>(x);
}

template <typename T>
[[nodiscard]] static T sz(auto&& x) {
  return static_cast<T>(x.size());
}
#endif

static void NO() {
  std::cout << "NO\n";
}

static void YES() {
  std::cout << "YES\n";
}

template <typename T>
using vec = std::vector<T>;

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
  vector<string> grid(n);
  for (auto& e : grid)
    cin >> e;
  /*
     core strategy: walk every char in tL region, find other 3 matching chars
rotationally
     - find formula
     sort, dist is sum of char distances for each smaller than biggest (can only
inc char)

     this is ans

     optimizes walking "rin"

impl: fill in grid as we go fore easer coverage

    actually, just walk top side
     */

  u32 ans = 0;
  for (i32 r = 0; r < n / 2; ++r) {
    // NOTE: missed this condition + other vars, made unecessary
    // // no need for pairs
    // why is auto comment on, fix the autogroup
    for (i32 c = r; c < n - 1 - r; ++c) {
      char big = max({grid[r][c], grid[c][n - 1 - r],
                      grid[n - 1 - r][n - 1 - c], grid[n - 1 - c][r]});

      ans += big - grid[r][c];
      ans += big - grid[c][n - 1 - r];
      ans += big - grid[n - 1 - r][n - 1 - c];
      ans += big - grid[n - 1 - c][r];
    }
  }
  cout << ans << endl;
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  u32 tc = 1;
  cin >> tc;

  for (u32 t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
