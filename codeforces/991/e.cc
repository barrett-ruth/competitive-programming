#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) static_cast<int>((x).size())
#define FOR(i, x) for (int i = 0; i < (x).size(); ++i)

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

void solve() {
  string a, b, c;
  cin >> a >> b >> c;

  if (a.size() < b.size()) {
    swap(a, b);
  }

  vector<int> dp(b.size() + 1, 0);

  for (int j = 1; j <= b.size(); ++j) {
    dp[j] = dp[j - 1] + (b[j - 1] != c[j - 1]);
  }

  for (int i = 1; i <= a.size(); ++i) {
    dp[0] += (a[i - 1] != c[i - 1]);
    for (int j = 1; j <= b.size(); ++j) {
      int k = i + j - 1;
      dp[j] = min(dp[j] + (a[i - 1] != c[k]), dp[j - 1] + (b[j - 1] != c[k]));
    }
  }

  cout << dp[b.size()] << '\n';
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
