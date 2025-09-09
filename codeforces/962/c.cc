#include <bits/stdc++.h>  // {{{

#include <version>
#ifdef __cpp_lib_ranges_enumerate
#include <ranges>
namespace rv = std::views;
namespace rs = std::ranges;
#endif

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

  string a, b;
  cin >> a >> b;

  vec<vec<u32>> fa(n + 1, vec<u32>(26, 0)), fb(n + 1, vec<u32>(26, 0));

  for (u32 i = 1; i <= n; ++i) {
    fa[i] = fa[i - 1];
    ++fa[i][a[i - 1] - 'a'];
    fb[i] = fb[i - 1];
    ++fb[i][b[i - 1] - 'a'];
  }

  u32 l, r;
  for (u32 i = 0; i < q; ++i) {
    cin >> l >> r;

    u64 acc = 0;
    for (u32 j = 0; j < 26; ++j) {
      auto adiff = fa[r][j] - fa[l - 1][j];
      auto bdiff = fb[r][j] - fb[l - 1][j];

      acc += max(adiff, bdiff) - min(adiff, bdiff);
    }

    u64 ans = acc / 2;
    println("{}", ans);
  }
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
