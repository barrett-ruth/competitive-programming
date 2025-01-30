#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) static_cast<int>((x).size())
#define FOR(x) for (int i = 0; i < (x).size(); ++i)

// variable iterator macro needed
// NOTE: can prob optimize by sorting queries
// fix matchparen highlight
// NOTE: didn't realize queries are independent (bruh)

void solve() {
  string s;
  cin >> s;

  auto valid = [&](int i) -> bool {
    return i >= 0 && i < sz(s) - 3 && s[i] == '1' && s[i + 1] == '1' &&
           s[i + 2] == '0' && s[i + 3] == '0';
  };

  int count = 0;

  for (int i = 0; i < sz(s); ++i) {
    if (valid(i)) {
      ++count;
    }
  }

  int q;
  cin >> q;

  for (int _ = 0; _ < q; _++) {
    int i;
    char v;
    cin >> i >> v;
    --i;

    if (s[i] != v) {
      bool left = false;
      for (int j = i - 3; j <= i; ++j) {
        if (valid(j)) {
          left = true;
          break;
        }
      }

      s[i] = v;

      bool right = false;
      for (int j = i - 3; j <= i; ++j) {
        if (valid(j)) {
          right = true;
          break;
        }
      }

      count += (right - left);
    }
    cout << (count > 0 ? "YES" : "NO") << '\n';
  }
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
