#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
string s, t;
int n;
void solve() {
  cin >> n;
  cin >> s >> t;
  sort(begin(s), end(s));
  sort(begin(t), end(t));
  if (s == t) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << '\n';
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}

