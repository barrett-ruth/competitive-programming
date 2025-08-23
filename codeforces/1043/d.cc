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

const int MAXD = 18;
u64 POW10[MAXD], PREF[MAXD];

u64 digit_prefix_sum(u64 n) {
  if (n < 10)
    return n * (n + 1) / 2;
  int d = 0;
  while (POW10[d + 1] <= n)
    ++d;
  u64 p = POW10[d];
  u64 msd = n / p;
  u64 rest = n % p;
  return msd * PREF[d] + (msd * (msd - 1) / 2) * p + msd * (rest + 1) +
         digit_prefix_sum(rest);
}

void solve() {
  u64 k;
  cin >> k;
  u64 K = k, D = 1;
  for (u32 i = 0; i < 15; ++i) {
    u64 base_count = (POW10[i + 1] - POW10[i]) * (i + 1);
    if (base_count > K) {
      D = i + 1;
      break;
    }
    K -= base_count;
  }
  u64 ans = 0;
  u64 x = POW10[D - 1] + K / D - 1;
  if (K % D) {
    u64 next = x + 1;
    for (u32 i = 0; i < D - (K % D); ++i)
      next /= 10;
    while (next) {
      ans += next % 10;
      next /= 10;
    }
  }
  ans += digit_prefix_sum(x);
  cout << ans << "\n";
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
