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
  i64 n, k;
  cin >> n >> k;

  vec<i64> costs(20);
  for (u32 x = 0; x <= 19; ++x) {
    costs[x] = (i64)powl(3, x + 1) + x * (i64)powl(3, x - 1);
  }

  i64 cost = 0;

  vec<i64> deals(costs.size(), 0);

  for (i32 i = costs.size() - 1; i >= 0; --i) {
    auto w = (u64)powl(3, i);
    auto times = n / w;
    n -= w * times;
    cost += costs[i] * times;
    deals[i] += times;
  }

  i64 left = k - accumulate(all(deals), 0LL);

  if (left < 0) {
    println("-1");
    return;
  }

  for (i32 i = costs.size() - 1; left > 0 && i > 0; --i) {
    i64 y = min(left / 2, deals[i]);

    left -= 2 * y;
    cost -= y * costs[i];
    cost += 3 * y * costs[i - 1];

    deals[i] -= y;
    deals[i - 1] += 3 * y;
  }

  println("{}", cost);
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
