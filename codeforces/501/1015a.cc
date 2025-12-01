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

void solve() {
  u32 n, m;
  cin >> n >> m;
  vector<pair<u32, u32>> a(n);
  for (auto& e : a) {
    cin >> e.first >> e.second;
  }
  sort(begin(a), end(a));
  u32 j = 0;
  vector<u32> ans;
  for (u32 i = 1; i <= m; ++i) {
    while (i > a[j].second) {
      ++j;
    }
    if (j == n || i < a[j].first || i > a[j].second) {
      ans.push_back(i);
    }
  }
  println("{}", ans.size();
  for (auto& e : ans) print("{} ", e); println();
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
  for (u32 t = 0; t < tc; ++t) {
    solve();
  }
  return 0;
}
// }}}
