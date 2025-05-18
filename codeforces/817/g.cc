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

  if (n == 3) {
    cout << "1 2 3\n";
    return;
  }

  vec<u32> a(n, 0);

  u32 odd_slots = n / 2;
  u32 even_slots = ceil(n / 2.0);

  for (u32 i = 0; i < n; i += 2) {
    a[i] = i / 2 + 1;
    if (i + 1 < n)
      a[i + 1] = a[i] | ((u32)1 << 30);
  }

  if (n & 1) {
    a[n - 1] = 0;
  }

  if (odd_slots & 1) {
    a[odd_slots * 2 - 3] ^= a[odd_slots * 2 - 1];
    a[odd_slots * 2 - 1] = (u32)1 << 29;
    a[odd_slots * 2 - 3] |= (u32)1 << 29;
    a[odd_slots * 2 - 3] |= (u32)1 << 30;
  }

  for (u32 i = 0; i < n; ++i) {
    cout << a[i] << " \n"[i == n - 1];
  }
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
