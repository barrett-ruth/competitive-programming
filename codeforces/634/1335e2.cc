#include <bits/stdc++.h> // {{{

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
using u16 = uint16_t;
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

template <typename T> using vec = std::vector<T>;

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

  vec<u16> a(n);
  for (auto &e : a)
    cin >> e;

  vec<vec<u32>> f(200 + 1);
  vec<vec<u32>> pref(200 + 1, vec<u32>(n + 1, 0));

  u32 ans = 0;

  for (u32 i = 1; i <= n; ++i) {
    f[a[i - 1]].push_back(i);

    for (u32 x = 1; x <= 200; ++x) {
      pref[x][i] = pref[x][i - 1];
    }

    ans = max(ans, ++pref[a[i - 1]][i]);
  }

  for (u16 x = 1; x <= 200; ++x) {
    for (u32 A = 1; A <= f[x].size() / 2; ++A) {
      i32 l = f[x][A - 1] + 1;
      i32 r = f[x][f[x].size() - A] - 1;

      if (l > r) {
        continue;
      }

      u32 B = 0;
      for (u16 y = 1; y <= 200; ++y) {
        B = max(B, pref[y][r] - pref[y][l - 1]);
      }

      ans = max(ans, 2 * A + B);
    }
  }

  println("{}", ans);
}

int main() { // {{{
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
