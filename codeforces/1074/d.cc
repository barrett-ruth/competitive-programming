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

bitset<2 * 100000 + 1> dirty;
void solve() {
  dirty.reset();
  u32 n, m;
  u64 h;
  cin >> n >> m >> h;
  vector<pair<u64, u64>> a(n);
  for (u32 i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = a[i].first;
  }

  u64 b, c;
  for (u32 i = 0; i < m; ++i) {
    cin >> b >> c;
    --b;
    if (dirty[b]) {
      dirty[b] = false;
      a[b].second = a[b].first;
    }
    a[b].second += c;
    if (a[b].second > h) {
      dirty.set();
    }
  }

  for (u32 i = 0; i < n; ++i) {
    print("{}{}", dirty[i] ? a[i].first : a[i].second, " \n"[i == n - 1]);
  }
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
} // vim: set foldmethod=marker foldmarker={{{,}}}
