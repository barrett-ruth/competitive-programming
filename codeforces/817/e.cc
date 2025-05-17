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

  vec<vec<u64>> prefix(1000 + 1, vec<u64>(1000 + 1, 0));

  for (u32 i = 0; i < n; ++i) {
    u64 h, w;
    cin >> h >> w;
    prefix[h][w] += h * w;
  }

  for (u32 i = 1; i <= 1000; ++i)
    for (u32 j = 1; j <= 1000; ++j)
      prefix[i][j] +=
          prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];

  for (u32 i = 0; i < q; ++i) {
    u32 hs, ws, hb, wb;
    cin >> hs >> ws >> hb >> wb;

    u64 ans = prefix[hb - 1][wb - 1] - prefix[hs][wb - 1] - prefix[hb - 1][ws] +
              prefix[hs][ws];

    cout << ans << '\n';
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
