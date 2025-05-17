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
  u32 n;
  cin >> n;

  vec<u32> a(n);
  for (u32 i = 0; i < n; i += 2) a[i] = i >> 1;

  u32 xe = 0;
  for (u32 i = 0; i < n; i += 2) xe ^= a[i];

  u32 odd = n >> 1;
  if (!odd) {
    for (u32 i = 0; i < n; ++i) cout << a[i] << " \n"[i == n - 1];
    return;
  }

  const u32 BIG = 1u << 20;
  u32 xo = 0;
  for (u32 k = 0; k + 2 < odd; ++k) {
    a[1 + 2 * k] = BIG + k;
    xo ^= a[1 + 2 * k];
  }

  if (odd == 1) {
    a[1] = BIG;
    a[0] ^= xe ^ BIG;
  } else {
    u32 diff = xe ^ xo;
    u32 p = BIG + odd - 2;
    a[2 * odd - 3] = p;
    a[2 * odd - 1] = p ^ diff;
  }

  for (u32 i = 0; i < n; ++i)
    cout << a[i] << " \n"[i == n - 1];
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
