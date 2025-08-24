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
  vec<vec<u32>> tree(n + 1);
  for (u32 i = 2; i <= n; ++i) {
    u32 a;
    cin >> a;
    tree[i].push_back(a);
    tree[a].push_back(i);
  }

  string s;
  cin >> s;
  s = ' ' + s;

  vec<vec<u32>> dp(n + 1, vec<u32>(2));

  auto dfs = [&](auto&& self, u32 u, u32 p) -> void {
    u32 sleepCost = (s[u] == 'P') ? MAX<u64> : 0;
    u32 partyCost = (s[u] == 'S') ? MAX<u64> : 0;

    for (u32 v : tree[u]) {
      if (v == p) {
        continue;
      }

      self(self, v, u);
      u32 bestChild = min(dp[v][0], dp[v][1]);
      u32 cutCost = (bestChild == MAX<u64>) ? MAX<u64> : bestChild + 1;

      sleepCost += min(dp[v][0], cutCost);
      partyCost += min(dp[v][1], cutCost);
    }

    dp[u][0] = sleepCost;
    dp[u][1] = partyCost;
  };

  dfs(dfs, 1, 0);
  cout << *min_element(all(dp[1])) << '\n';
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
