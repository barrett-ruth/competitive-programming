#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) static_cast<int>((x).size())
#define FOR(i, x) for (int i = 0; i < (x).size(); ++i)

template <typename T> T max() { return numeric_limits<T>::max(); }
template <typename T> T min() { return numeric_limits<T>::min(); }

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

void solve() {
  int n;
  cin >> n;

  unordered_map<int, vector<int>> graph;

  while (--n) {
    int u, v;
    cin >> u >> v;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  auto ans = min<int>();

  auto is_leaf = [&graph](int u) {
    return (u != 1 && graph[u].size() == 1) || (u == 1) && graph[u].empty();
  };

  auto dfs = [&](auto &dfs, int u, int parent) -> int {
    if (u == parent || is_leaf(u)) {
      return 0;
    }

    int first = 0, second = 0;

    for (auto v : graph[u]) {
      if (v == parent)
        continue;

      auto through = dfs(dfs, v, u);

      if (through > first) {
        second = through;
        swap(first, second);
      } else if (through > second) {
        second = through;
      }
    }

    int remove_u_and_one_child = sz(graph[u]) - (u != 1) - (first != 0) + first;
    int remove_through_u =
        sz(graph[u]) - (u != 1) - (first != 0) - (second != 0) + first + second;
    int no_remove_u = 1 + first;

    ans = max(ans, max(remove_through_u, no_remove_u));

    return remove_u_and_one_child;
  };

  std::cout << max(ans, dfs(dfs, 1, -1)) << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
