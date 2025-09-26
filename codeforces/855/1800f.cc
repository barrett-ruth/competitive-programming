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

vector<u32> parities(200000, 0);
vector<bitset<32>> present(200000);

void solve() {
  u32 n;
  cin >> n;

  string s;
  for (u32 i = 0; i < n; ++i) {
    cin >> s;
    for (auto c : s) {
      parities[i] ^= 1 << (c - 'a');
      present[i].set(c - 'a');
    }
  }

  u64 ans = 0;
  unordered_map<u32, u64> f;

  for (u32 c = 0; c < 26; ++c) {
    u32 mask = ((1 << 26) - 1) ^ (1 << c);
    for (u32 i = 0; i < n; i++) {
      if (present[i].test(c))
        continue;
      ans += f[parities[i] ^ mask];
      ++f[parities[i]];
    }
    f.clear();
  }

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
  // std::cin >> tc;

  for (u32 t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
