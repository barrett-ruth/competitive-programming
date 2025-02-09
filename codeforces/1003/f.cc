//  {{{
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
[[nodiscard]] static T sc(auto &&x) {
  return static_cast<T>(x);
}

template <typename T>
[[nodiscard]] static T sz(auto &&x) {
  return static_cast<T>(x.size());
}

template <typename... Args>
void pr(std::format_string<Args...> fmt, Args &&...args) {
  std::print(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void pr(std::format_string<Args...> fmt) {
  std::print(fmt);
}

template <typename... Args>
void prln(std::format_string<Args...> fmt, Args &&...args) {
  std::println(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void prln(std::format_string<Args...> fmt) {
  std::println(fmt);
}

void prln() {
  std::println();
}

void prln(auto const &t) {
  std::println("{}", t);
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
//  }}}

void solve() {
  int n;
  cin >> n;
  vec<int> a(n + 1);
  for (int i = 1; i < sz<int>(a); ++i) {
    cin >> a[i];
  }

  vec<vec<int>> tree(n + 1, vec<int>());
  string ans(n, '0');

  int root;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    root = u;
    tree[u].pb(v);
    tree[v].pb(u);
  }

  unordered_map<int, unordered_map<int, int>> children;
  vec<int> par(n + 1, -1);
  par[root] = root;

  queue<int> q{{root}};

  while (!q.empty()) {
    int size = sz<int>(q);
    while (size--) {
      auto u = q.front();
      q.pop();
      for (auto v : tree[u]) {
        if (par[v] != -1)
          continue;
        par[v] = u;
        q.push(v);
        if (++children[u][a[v]] == 2)
          ans[a[v] - 1] = '1';
      }
    }
  }

  q.push(root);

  for (int u = 1; u <= n; ++u) {
    if (par[u] != u && a[u] == a[par[u]] ||
        par[u] != root && a[u] == a[par[par[u]]])
      ans[a[u] - 1] = '1';
  }

  prln("{}", ans);
}

// {{{
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
// }}}
