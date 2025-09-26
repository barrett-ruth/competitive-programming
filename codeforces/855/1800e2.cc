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

bitset<2 * 100000> seen;
void solve() {
  seen.reset();
  u32 n, k;
  cin >> n >> k;
  string s, t;
  cin >> s >> t;

  u32 ans = 0;
  vector<u32> f(26, 0);

  auto dfs = [&](auto &&self, i32 i) -> void {
    if (i < 0 || i >= n || seen[i])
      return;
    seen[i] = true;
    ++f[s[i] - 'a'];
    --f[t[i] - 'a'];
    for (auto d : {i - k, i - k - 1, i + k, i + k + 1}) {
      self(self, d);
    }
  };

  bool ok = true;
  for (i32 i = 0; i < n && ok; ++i) {
    if (!seen[i]) {
      dfs(dfs, i);
      ok &= count(f.begin(), f.end(), 0) == 26;
      f.assign(26, 0);
    }
  }

  cout << (ok ? "YES" : "NO") << '\n';
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
