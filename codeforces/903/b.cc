#include <bits/stdc++.h>  // {{{

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
  u32 a, b, c;

  cin >> a >> b >> c;

  for (u32 mask = 0; mask < (1 << 9) - 1; ++mask) {
    if (__builtin_popcount(mask) > 3)
      continue;

    u32 right = __builtin_popcount(mask & ((1 << 3) - 1));
    u32 mid = __builtin_popcount((mask >> 3) & ((1 << 3) - 1));
    u32 left = __builtin_popcount((mask >> 6) & ((1 << 3) - 1));

    if (left && a % (left + 1))
      continue;
    if (mid && b % (mid + 1))
      continue;
    if (right && c % (right + 1))
      continue;

    u32 A = left ? a / (left + 1) : a;
    u32 B = mid ? b / (mid + 1) : b;
    u32 C = right ? c / (right + 1) : c;

    if (A == B && B == C) {
      YES();
      return;
    }
  }

  NO();
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  u32 tc = 1;
  cin >> tc;

  for (u32 t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
