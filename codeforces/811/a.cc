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
  i32 n, H, M;
  cin >> n >> H >> M;

  pair<i32, i32> A{H,M};

  vector<pair<i32, i32>> alarms(n);
  for (auto& e : alarms) {
    cin >> e.first >> e.second;
  }

  sort(begin(alarms), end(alarms));

  i32 ans = 0;

  for (i32 i = 0; i < n; ++i) {
    auto& alarm = alarms[i];
    if (alarm >= A) {
      ans = i;
      break;
    }
  }

  auto& alarm = alarms[ans];
  i32 diff = abs(alarm.first * 60 + alarm.second - (A.first * 60 + A.second));
  if (alarm < A) {
    diff = 24 * 60 - diff;
  }

  println("{} {}", diff / 60, diff % 60);
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
