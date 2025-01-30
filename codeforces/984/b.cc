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

#define MAX_K 2 * 100000

// clearing/resetting vector
// clean way for x^n; exppow
// sorting in orders
// totally misread: test case time *
// how does time work???? per-test case... or

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> brand_to_cost(k + 1, 0);

  for (int i = 0; i < k; ++i) {
    int b, c;
    cin >> b >> c;
    brand_to_cost[b] += c;
  }

  sort(all(brand_to_cost), std::greater<int>{});

  std::cout << accumulate(brand_to_cost.begin(),
                          brand_to_cost.begin() + min(n, sz(brand_to_cost)),
                          0LL)
            << '\n';
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
