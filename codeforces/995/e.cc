#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using d64 = double;
using d128 = long double;
template <typename T>
using vec = std::vector<T>;
template <typename T, size_t N>
using arr = std::array<T, N>;
template <typename T1, typename T2>
using pai = std::pair<T1, T2>;

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

static void NO() {
  std::cout << "NO\n";
}

static void YES() {
  std::cout << "YES\n";
}

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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
  vec<i64> a(n), b(n);
  for (auto& e : a)
    cin >> e;
  for (auto& e : b) {
    cin >> e;
  }

  i64 ans = 0;
  vec<i64> prices;
  for (i64 i = 0; i < n; ++i) {
    prices.push_back(a[i]);
    prices.push_back(b[i]);
  }
  prices.push_back(0);
  sort(all(prices));
  prices.erase(unique(all(prices)), prices.end());
  sort(all(a));
  sort(all(b));
  // fundamentally cooked - thought oculd binary search over the range (this is just not tree)
  // "pass tc = right" mindset - braindead
  // low patience -> lack of focus (phone?) gave up on e and f, espec. when 
  // f was doable

  for (i64 price : prices) {
    i64 A = n - distance(a.begin(), lower_bound(all(a), price));
    i64 B = n - distance(b.begin(), lower_bound(all(b), price));
    i64 profit = price * B;

    if (B - A <= k) {
      ans = max(ans, profit);
    }
  }

  cout << ans << '\n';
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  int tc = 1;
  cin >> tc;

  for (int t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
