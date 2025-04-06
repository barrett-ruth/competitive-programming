#include <bits/stdc++.h>
using namespace std;

void YES() {
  cout << "YES\n";
}
void NO() {
  cout << "NO\n";
}

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<vector<int>> graph(n + 1);
  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vector<int> parent(n + 1, -1);
  vector<int> visited(n + 1, 0);
  int cycle_start = -1, cycle_end = -1;
  function<bool(int, int)> dfs_cycle = [&](int u, int par) {
    visited[u] = 1;
    for (int v : graph[u]) {
      if (v == par)
        continue;
      if (visited[v] == 1) {
        cycle_start = v;
        cycle_end = u;
        return true;
      }
      parent[v] = u;
      if (dfs_cycle(v, u))
        return true;
    }
    return false;
  };

  dfs_cycle(1, -1);

  vector<int> cycle_nodes;
  if (cycle_start != -1) {
    for (int u = cycle_end; u != cycle_start; u = parent[u]) {
      cycle_nodes.push_back(u);
    }
    cycle_nodes.push_back(cycle_start);
  }

  unordered_set<int> cycle(cycle_nodes.begin(), cycle_nodes.end());

  auto bfs_dist = [&](int start) -> vector<int> {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : graph[u]) {
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    return dist;
  };

  vector<int> dist_a = bfs_dist(a);
  vector<int> dist_b = bfs_dist(b);

  bool can_avoid = false;
  for (int node : cycle_nodes) {
    if (dist_b[node] < dist_a[node]) {
      can_avoid = true;
      break;
    }
  }

  if (can_avoid) {
    YES();
  } else {
    NO();
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
