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
  i64 k;
  cin >> n >> k;
  vec<u64> a(n);
  for (auto& e : a)
    cin >> e;

  const u32 B = 31;
  vec<i64> dp(B + 1, MIN<i64>), ndp(B + 1, MIN<i64>);
  dp[0] = 0;

  for (u32 i = 0; i < n; ++i) {
    fill(all(ndp), MIN<i64>);
    u32 upto = min<u32>(B, i);
    for (u32 b = 0; b <= upto; ++b) {
      if (dp[b] == MIN<i64>)
        continue;

      i64 gain_good = sc<i64>(a[i] >> b) - k;
      ndp[b] = max(ndp[b], dp[b] + gain_good);

      u32 b2 = min<u32>(B, b + 1);
      i64 gain_bad = sc<i64>(a[i] >> b2);
      ndp[b2] = max(ndp[b2], dp[b] + gain_bad);
    }
    dp.swap(ndp);
  }

  println("{}", *max_element(all(dp)));
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
