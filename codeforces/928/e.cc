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
  u64 n, k;
  cin >> n >> k;

  /*
     initially lays down ceil(n / 2.0) cards

     if found, its just 2 * k

     n - ceil(n / 2.0) left

     lays down 2 * odds

note: only odd # turns matter

     n = 24
     1 3 5 7 9 11 13 15 17 19 21 23 -> 2 4 6 8 10 12 ... left
     2 6 10 14
     div. both sides by 2:
     1 2 3 4 5 6 <- n - ceil(n / 2.0) left
     continue, log(n) itme
     3 9 ... <- don't matter

     div by 2
     */

  u64 multiplier = 1;
  while (k > (u64)ceil(n / 2.0)) {
    k -= (u64)ceil(n / 2.0);
    n -= (u64)ceil(n / 2.0);
    multiplier *= 2;
  }

  println("{}", multiplier * (1 + 2 * (k - 1)));
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
