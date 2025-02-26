#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

template <typename T>
constexpr T MIN = std::numeric_limits<T>::min();

template <typename T>
constexpr T MAX = std::numeric_limits<T>::max();

template <typename T>
[[nodiscard]] static T sc(auto &&x) {
  return static_cast<T>(x);
}

template <typename T>
[[nodiscard]] static T sz(auto &&x) {
  return static_cast<T>(x.size());
}

using ll = long long;
using ld = long double;
template <typename T>
using vec = std::vector<T>;
template <typename T, size_t N>
using arr = std::array<T, N>;

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
//  }}}

void solve() {
  int m;
  cin >> m;
  string s;
  vec<vec<ld>> recs, circs;
  while (m--) {
    cin >> s;
    ld x1, y1, x2, y2, h, k, r;
    if (s[0] == 'r') {
      cin >> x1 >> y1 >> x2 >> y2;
      recs.pb({x1, y1, x2, y2});
    } else {
      cin >> h >> k >> r;
      circs.pb({h, k, r});
    }
  }
  int shots;
  cin >> shots;
  ld x, y;
  while (shots--) {
    cin >> x >> y;
    ll ans = 0;
    for (auto &r : recs) {
      if (y >= r[1] && y <= r[3] && x >= r[0] && x <= r[2])
        ++ans;
    }
    for (auto &c : circs) {
      if (sqrtl(powl(x - c[0], 2) + powl(y - c[1], 2)) <= c[2]) {
        ++ans;
      }
    }
    cout << ans << endl;
  }
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
// }}}
