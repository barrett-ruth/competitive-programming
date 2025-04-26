#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
using f128 = long double;

template <typename T>
constexpr T MIN = std::numeric_limits<T>::min();

template <typename T>
constexpr T MAX = std::numeric_limits<T>::max();

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second

#ifdef LOCAL
#define db(...) std::print(__VA_ARGS__)
#define dbln(...) std::println(__VA_ARGS__)
#else
#define db(...)
#define dbln(...)
#endif
//  }}}

void solve() {
  i32 n;
  cin >> n;
  map<pair<i64, i64>, i64> m;
  m[{0, 0}] = 0;
  char dir;
  i64 delta;
  i64 x = 0, y = 0;
  i64 ans = MAX<i64>, t = 0;
  while (n--) {
    cin >> dir >> delta;

    i64 dx = 0, dy = 0;

    switch (dir) {
      case 'N':
        dy = 1;
        break;
      case 'E':
        dx = 1;
        break;
      case 'S':
        dy = -1;
        break;
      case 'W':
        dx = -1;
        break;
    }

    for (i64 i = 0; i < abs(delta); ++i) {
      ++t;
      x += dx;
      y += dy;
      if (m.find({x, y}) != m.end()) {
        ans = min(ans, t - m[{x, y}]);
      }
      m[{x, y}] = t;
    }
  }

  if (ans == MAX<i64>)
    cout << "-1\n";
  else
    cout << ans << '\n';
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

#define PROBLEM_NAME "mowing"

#ifdef LOCAL
  freopen("io/" PROBLEM_NAME ".in", "r", stdin);
  freopen("io/" PROBLEM_NAME ".out", "w", stdout);
#else
  freopen(PROBLEM_NAME ".in", "r", stdin);
  freopen(PROBLEM_NAME ".out", "w", stdout);
#endif

  solve();

  return 0;
}
// }}}
