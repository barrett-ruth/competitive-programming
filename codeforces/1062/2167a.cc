#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
void solve() {
  a.resize(4);
  for (int i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }

  sort(begin(a), end(a));

  if (a.front() == a.back()) {
    cout << "YES";
  } else
    cout << "NO";
  cout << '\n';
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}

