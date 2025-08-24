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

  auto dfs = [&](auto&& self, u32 u, u32 p) -> vec<u32> {
    vec<u32> dp(2);
    dp[0] = (s[u] == 'P') ? 1 << 30 : 0;
    dp[1] = (s[u] == 'S') ? 1 << 30 : 0;
    for (u32 v : tree[u]) {
      if (v == p)
        continue;
      auto prev = self(self, v, u);
      dp[0] += min(prev[0], prev[1] + 1);
      dp[1] += min(prev[1], prev[0] + 1);
    }
    return dp;
  };

  auto ans = dfs(dfs, 1, 0);
  cout << *min_element(all(ans)) << '\n';
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
