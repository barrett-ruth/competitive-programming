#include <bits/stdc++.h>  // {{{

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
template <typename T>
constexpr T MIN = std::numeric_limits<T>::min();

template <typename T>
constexpr T MAX = std::numeric_limits<T>::max();
#endif

#ifdef LOCAL
#define db(...) std::print(__VA_ARGS__)
#define dbln(...) std::println(__VA_ARGS__)
#else
#define db(...)
#define dbln(...)
#endif
//  }}}

bitset<1000 + 1> seen;

void solve() {
  seen.reset();

  u32 n;
  cin >> n;
  vector<u32> a(n);
  for (auto& e : a) cin >> e;
  u32 write = n;
  for (i32 i = n - 1; i >= 0; --i) {
    if (!seen[a[i]]) {
      a[--write] = a[i];
      seen.set(a[i]);
    }
  }
  println("{}", n - write);
  for (u32 i = write; i < n; ++i) {
    print("{} ", a[i]);
  }
  println();
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
  // std::cin >> tc;
  for (u32 t = 0; t < tc; ++t) {
    solve();
  }
  return 0;
}
// }}}
