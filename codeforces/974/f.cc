#include <bits/stdc++.h>

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

template <typename T>
constexpr T MIN = std::numeric_limits<T>::min();

template <typename T>
constexpr T MAX = std::numeric_limits<T>::max();

template <typename T>
[[nodiscard]] static T sc(auto&& x) {
  return static_cast<T>(x);
}

template <typename T>
[[nodiscard]] static int sz(auto&& x) {
  return static_cast<int>(x.size());
}

template <typename... Args>
void pr(std::format_string<Args...> fmt, Args&&... args) {
  std::print(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void prln(std::format_string<Args...> fmt, Args&&... args) {
  std::println(fmt, std::forward<Args>(args)...);
}

using ll = long long;
using ld = long double;
template <typename T>
using vec = std::vector<T>;

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

vec<vec<ll>> tree;
vec<ll> a;

void solve() {
  int n, c;
  cin >> n >> c;

  a.resize(n + 1);
  for (int i = 1; i < n + 1; ++i) {
    cin >> a[i];
  }

  tree.assign(n + 1, vec<ll>());

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;

    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  vec<vec<ll>> dp(n + 1, vec<ll>(2, 0));
  auto dfs = [&](int u, int parent, auto&& self) -> void {
    ll take = a[u] - c * tree[u].size();
    ll dont = 0;
    for (auto v : tree[u]) {
      if (v == parent) continue;
      self(v, u, self);
      take += max(dp[v][0] + c, dp[v][1]);
      dont += max(dp[v][0], dp[v][1] + c);
    }
    dp[u][0] = dont;
    dp[u][1] = take;
  };

  dfs(1, -1, dfs);

  prln("{}", max(dp[1][0], dp[1][1]));
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
