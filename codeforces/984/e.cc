#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) static_cast<int>((x).size())
#define FOR(x) for (int i = 0; i < (x).size(); ++i)

void solve() {
  int n, k, q;
  cin >> n >> k >> q;

  vector<vector<int>> b(k + 1, vector<int>(n + 1, 0));

  int v;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      cin >> v;
      b[j][i] = b[j][i - 1] | v;
    }
  }

  while (q--) {
    int m;
    cin >> m;

    int l = 0, r = n - 1;

    while (m--) {
      int R, v;
      char c;
      cin >> R;
      cin >> c;
      cin >> v;

      if (c == '<') {
        int i = distance(b[R].begin() + 1, lower_bound(all(b[R]), v)) - 1;
        r = min(r, i);
      } else {
        int i = distance(b[R].begin() + 1, upper_bound(all(b[R]), v));
        l = max(l, i);
      }
    }

    if (l <= r) {
      cout << l + 1 << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // int t;
  // cin >> t;

  // while (t--) {
  solve();
  // }

  return 0;
}
