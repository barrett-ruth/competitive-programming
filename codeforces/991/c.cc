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
  string n;
  cin >> n;

  long long total = 0, twos = 0, threes = 0;

  for (char c : n) {
    int digit = c - '0';
    if (digit == 2)
      ++twos;
    else if (digit == 3)
      ++threes;
    total += digit;
  }

  for (long long i = 0; i < std::min(10LL, twos + 1); ++i) {
    for (long long j = 0; j < std::min(10LL, threes + 1); ++j) {
      if ((total + i * 2 + j * 6) % 9 == 0) {
        cout << "YES\n";
        return;
      }
    }
  }

  cout << "NO\n";
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
