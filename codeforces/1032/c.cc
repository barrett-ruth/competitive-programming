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
  u32 n, m;
  cin >> n >> m;

  vec<vec<u32>> grid(n, vec<u32>(m));
  for (auto& row : grid)
    for (auto& cell : row)
      cin >> cell;

  u32 M = 0;
  for (auto& row : grid)
    for (auto cell : row)
      M = max(M, cell);

  unordered_map<u32, u32> M_col, M_row;

  u32 total_M = 0;

  for (u32 i = 0; i < n; ++i) {
    for (u32 j = 0; j < m; ++j) {
      M_row[i] += grid[i][j] == M;
      // NOTE: had typo here, `=` instead of `==`
      total_M += grid[i][j] == M;
    }
  }

  for (u32 j = 0; j < m; ++j) {
    for (u32 i = 0; i < n; ++i) {
      M_col[j] += grid[i][j] == M;
    }
  }

  for (u32 i = 0; i < n; ++i) {
    for (u32 j = 0; j < m; ++j) {
      u32 M_count = M_row[i] + M_col[j] - (grid[i][j] == M);

      if (M_count == total_M) {
        println("{}", M - 1);
        return;
      }
    }
  }

  println("{}", M);
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
