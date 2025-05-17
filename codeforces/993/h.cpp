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
  u32 n, q;
  cin >> n >> q;

  vec<vec<u64>> grid(n, vec<u64>(n));

  for (auto& r : grid)
    for (auto& c : r)
      cin >> c;

  vec<vec<u64>> one(n + 1, vec<u64>(n + 1, 0));
  auto colwise = one;
  auto rowwise = one;

  for (u32 i = 1; i <= n; ++i) {
    for (u32 j = 1; j <= n; ++j) {
      one[i][j] = grid[i - 1][j - 1] + one[i - 1][j] + one[i][j - 1] -
                  one[i - 1][j - 1];
    }
  }

  for (u32 i = 1; i <= n; ++i) {
    for (u32 j = 1; j <= n; ++j) {
      colwise[i][j] = i * grid[i - 1][j - 1] + colwise[i][j - 1] +
                      colwise[i - 1][j] - colwise[i - 1][j - 1];
    }
  }

  for (u32 i = 1; i <= n; ++i) {
    for (u32 j = 1; j <= n; ++j) {
      rowwise[i][j] = j * grid[i - 1][j - 1] + rowwise[i][j - 1] +
                      rowwise[i - 1][j] - rowwise[i - 1][j - 1];
    }
  }

  u64 x1, y1, x2, y2;
  for (u32 i = 0; i < q; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;

    auto s =
        one[x2][y2] - one[x2][y1 - 1] - one[x1 - 1][y2] + one[x1 - 1][y1 - 1];
    auto sr = colwise[x2][y2] - colwise[x2][y1 - 1] - colwise[x1 - 1][y2] +
              colwise[x1 - 1][y1 - 1];
    auto sc = rowwise[x2][y2] - rowwise[x2][y1 - 1] - rowwise[x1 - 1][y2] +
              rowwise[x1 - 1][y1 - 1];

    u64 w = y2 - y1 + 1;

    u64 ans = w * (sr - (u64)x1 * s) + (sc - (u64)y1 * s) + s;

    cout << ans << " \n"[i == q - 1];
  }
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
