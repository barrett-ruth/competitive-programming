#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) static_cast<int>((x).size())
#define FOR(x) for (size_t i = 0; i < (x).size(); ++i)

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

void solve() {
  int n, m;
  cin >> n >> m;
  size_t length = 0, words = 0;
  bool order = true;
  string s;
  for (size_t i = 0; i < n; ++i) {
    cin >> s;
    if (length + s.size() <= m && order) {
      dbg(m);
      length += s.size();
      ++words;
    } else {
      order = false;
    }
  }
  cout << words << '\n';
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
