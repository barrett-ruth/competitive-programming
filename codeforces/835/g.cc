#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<vector<pair<int, int>>> tree(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    tree[u].emplace_back(v, w);
    tree[v].emplace_back(u, w);
  }

  unordered_set<int> xor_values;
  vector<int> xor_a(n + 1, 0);
  vector<bool> visited(n + 1, false);
  bool found = false;
  int target_xor = -1;

  // First DFS to compute xor_a and check if direct a->b is 0
  function<void(int, int)> dfs1 = [&](int u, int parent) {
    visited[u] = true;
    for (auto &[v, w] : tree[u]) {
      if (v != parent && !visited[v]) {
        xor_a[v] = xor_a[u] ^ w;
        if (v == b) {
          target_xor = xor_a[v];
          if (target_xor == 0) {
            found = true;
          }
        }
        dfs1(v, u);
      }
    }
  };

  dfs1(a, -1);
  if (found) {
    cout << "YES\n";
    return;
  }

  // Second DFS to collect xor values from a, excluding b
  visited.assign(n + 1, false);
  function<void(int, int)> dfs2 = [&](int u, int parent) {
    visited[u] = true;
    if (u != b) {
      xor_values.insert(xor_a[u]);
    }
    for (auto &[v, w] : tree[u]) {
      if (v != parent && !visited[v]) {
        dfs2(v, u);
      }
    }
  };

  dfs2(a, -1);

  // Third DFS to check if any node in b's subtree (or elsewhere) has xor_a[u]
  // == target_xor
  visited.assign(n + 1, false);
  function<bool(int, int)> dfs3 = [&](int u, int parent) {
    visited[u] = true;
    if (u != a && u != b && xor_values.count(xor_a[u] ^ target_xor)) {
      return true;
    }
    for (auto &[v, w] : tree[u]) {
      if (v != parent && !visited[v]) {
        if (dfs3(v, u)) {
          return true;
        }
      }
    }
    return false;
  };

  if (dfs3(b, -1)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
