#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) static_cast<int>((x).size())
#define FOR(x) for (size_t i = 0; i < (x).size(); ++i)
#define FORI(x) for (size_t i = 0; i < (x); ++i)

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);

  int total = 0;
  FOR(a) {
    int x;
    cin >> x;
    a[i] = x;
    total += x;
  }

  long long odds = 0, evens = 0;
  for (int i = 0; i < n; i++) {
    (i & 1 ? odds : evens) += a[i];
  }
  int odd_count = n >> 1, even_count = (n >> 1) + (n & 1);

  if (odds % odd_count == 0 && evens % even_count == 0 &&
      odds / odd_count == evens / even_count) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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
