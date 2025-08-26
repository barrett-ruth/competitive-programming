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
  vec<string> grid(n);
  for (auto& row : grid)
    cin >> row;

  u32 changes = 0;

  for (u32 i = 0; i < n / 2; ++i) {
    for (u32 j = 0; j < n / 2; ++j) {
      u32 ones = 0;
      ones += grid[i][j] == '1';
      ones += grid[j][n - 1 - i] == '1';
      ones += grid[n - 1 - i][n - 1 - j] == '1';
      ones += grid[n - 1 - j][i] == '1';
      changes += min(ones, 4 - ones);
    }
  }

  if (n % 2 == 1) {
    u32 mid = n / 2;
    for (u32 i = 0; i < n / 2; ++i) {
      u32 ones = 0;
      ones += grid[i][mid] == '1';
      ones += grid[mid][n - 1 - i] == '1';
      ones += grid[n - 1 - i][mid] == '1';
      ones += grid[mid][i] == '1';
      changes += min(ones, 4 - ones);
    }
  }

  println("{}", changes);
}

int main() {  // {{{
  std::cin.exceptions(std::cin.failbit);

#ifdef LOCAL
  std::cerr.rdbuf(std::cout.rdbuf());
  std::cout.setf(std::ios::unitbuf);
  std::cerr.setf(std::ios::unitbuf);
#else
  std::cin.tie(nullptr)->sync_with_stdio(false);
#endif

  u32 tc = 1;
  std::cin >> tc;

  for (u32 t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
