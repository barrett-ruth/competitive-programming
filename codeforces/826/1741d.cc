#include <bits/stdc++.h> // {{{

#include <version>
#ifdef __cpp_lib_ranges_enumerate
#include <ranges>
namespace rv = std::views;
namespace rs = std::ranges;
#endif

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
using f128 = long double;

#if __cplusplus >= 202002L
template <typename T> constexpr T MIN = std::numeric_limits<T>::min();

template <typename T> constexpr T MAX = std::numeric_limits<T>::max();
#endif

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
  vector<u32> a(n);
  for (auto &e : a)
    cin >> e;

  auto f = [&](auto &&self, i32 l, i32 r) -> i64 {
    if (l + 1 == r) {
      return 0;
    }

    i32 m = l + (r - l) / 2;

    i64 left = self(self, l, m);
    i64 right = self(self, m, r);

    if (left == -1 || right == -1) {
      return -1;
    }

    bool oknoswap = true;
    for (i32 i = l; i < r - 1; ++i) {
      oknoswap = oknoswap && (a[i] < a[i + 1]);
    }

    if (oknoswap) {
      return left + right;
    }

    bool okswap = true;
    for (i32 i = m, cnt = 0; cnt < r - l - 1; ++cnt) {
      i32 nxt = i == r - 1 ? l : i + 1;
      okswap = okswap && (a[i] < a[nxt]);
      i = nxt;
    }
    if (okswap) {
      for (i32 i = 0; i < m - l; ++i) {
        swap(a[l + i], a[m + i]);
      }
      return left + right + 1;
    }

    return -1;
  };

  cout << f(f, 0, n) << '\n';
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
