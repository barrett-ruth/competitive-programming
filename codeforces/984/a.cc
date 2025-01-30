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

void solve() {
  int n;
  cin >> n;
  vector<int> notes(n, 0);
  for (auto &x : notes)
    cin >> x;

  for (int i = 1; i < notes.size(); ++i) {
    auto diff = abs(notes[i] - notes[i - 1]);

    if (!(diff == 5 || diff == 7)) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
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
