#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) static_cast<int>((x).size())
#define FOR(x) for (size_t i = 0; i < (x).size(); ++i)

#ifndef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

#define PROBLEM_NAME "blocks"

void solve() {
  int N;
    cin >> N;
    vector<int> ans(26, 0);

    for(int i = 0; i < N; ++i) {
        string left, right;
        cin >> left >> right;
        vector<int> count_left(26, 0);
        for(char c : left) count_left[c - 'a']++;
        vector<int> count_right(26, 0);
        for(char c : right) count_right[c - 'a']++;
        for(int j = 0; j < 26; ++j) {
            ans[j] += max(count_left[j], count_right[j]);
        }
    }

    for(int count : ans) {
        cout << count << '\n';
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen(PROBLEM_NAME ".in", "r", stdin);
  freopen(PROBLEM_NAME ".out", "w", stdout);

  solve();

  return 0;
}
