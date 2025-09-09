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
  i32 n;
  cin >> n;
  vec<i64> a(n);
  for (auto& e : a)
    cin >> e;

  vec<i64> pref(n + 1, 0);
  for (i32 i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + a[i - 1];
  }

  u32 q;
  cin >> q;

  i64 u;
  i32 l;

  auto f = [&](i64 i) {
    auto S = pref[i] - pref[l - 1];
    return (u + 1) * S - S * (S + 1) / 2;
  };

  auto delta = [&](i64 i) {
    return f(i) - f(i - 1);
  };

  for (u32 i = 0; i < q; ++i) {
    cin >> l >> u;

    i32 L = l + 1, R = n;

    while (L <= R) {
      auto M = L + (R - L) / 2;

      if (delta(M) > 0) {
        L = M + 1;
      } else {
        R = M - 1;
      }
    }

    print("{}{}", L - 1, " \n"[i == q - 1]);
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
