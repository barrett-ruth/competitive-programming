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
  string s;
  cin >> n >> s;

  u64 ans = MAX<u64>;

  auto f = [&](string &t) {
    vector<u64> pos;
    for (u64 i = 0; i < n; i++)
      if (t[i] == 'a')
        pos.push_back(i);
    u64 m = pos.size();

    vector<u64> pref(m + 1), suff(m + 1);
    for (u64 i = 0; i < m; i++)
      pref[i + 1] = pref[i] + pos[i] - i;
    for (u64 i = m; i--;)
      suff[i] = suff[i + 1] + (n - (m - i)) - pos[i];

    for (u64 i = 0; i <= m; i++)
      ans = min<u64>(ans, pref[i] + suff[i]);
  };

  f(s);
  transform(s.begin(), s.end(), s.begin(),
            [](char c) { return c ^ 'a' ^ 'b'; });
  f(s);

  cout << ans << '\n';
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
