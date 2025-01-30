#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) static_cast<int>((x).size())
#define FOR(x) for (int i = 0; i < (x).size(); ++i)

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

constexpr auto _1543 = "1543";

int find_1543(const string &layer) {
  if (sz(layer) < 4) {
    return 0;
  }
  string extended = layer + layer.substr(0, 3);

  int count = 0;
  for (int i = 0; i < sz(layer); ++i) {
    bool found = true;
    for (int j = 0; j < 4; j++) {
      if (extended[i + j] != _1543[j]) {
        found = false;
        break;
      }
    }

    count += found;
  }
  return count;
}

string layer(const vector<string> &carpet, int n, int m, int i) {
  int top = i, bot = n - 1 - i, l = i, r = m - 1 - i;

  string pattern;
  for (int c = l; c <= r; c++) {
    pattern.push_back(carpet[top][c]);
  }
  for (int row = top + 1; row < bot; row++) {
    pattern.push_back(carpet[row][r]);
  }
  if (bot > top) {
    for (int c = r; c >= l; c--) {
      pattern.push_back(carpet[bot][c]);
    }
  }
  if (l < r) {
    for (int r = bot - 1; r > top; r--) {
      pattern.push_back(carpet[r][l]);
    }
  }

  return pattern;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<string> carpet(n);
  for (auto &x : carpet) {
    cin >> x;
  }

  long long ans = 0;
  const int LAYER_COUNT = min(n, m) / 2;

  for (int i = 0; i < LAYER_COUNT; ++i) {
    string ring = layer(carpet, n, m, i);
    ans += find_1543(ring);
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
