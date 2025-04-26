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
  vector<string> grid(3);
  for (auto& e : grid)
    cin >> e;

  u64 single = 0, two = 0;

  for (char c = 'A'; c <= 'Z'; ++c) {
    i32 ccountr = 0, dcountr = 0, ccountc = 0, dcountc = 0;
    bool done = false;
    for (u32 i = 0; i < 3 && !done; ++i) {
      ccountr = (grid[i][0] == c) + (grid[i][1] == c) + (grid[i][2] == c);
      ccountc = (grid[0][i] == c) + (grid[1][i] == c) + (grid[2][i] == c);
      if (ccountr == 3 || ccountc == 3) {
        ++single;
        done = true;
      }
    }
    ccountr = (grid[0][0] == c) + (grid[1][1] == c) + (grid[2][2] == c);
    ccountc = (grid[2][0] == c) + (grid[1][1] == c) + (grid[0][2] == c);
    if (!done && (ccountr == 3 || ccountc == 3))
      ++single;
    for (char d = 'A'; d < c; ++d) {
      bool done = false;
      for (u32 i = 0; i < 3 && !done; ++i) {
        ccountr = (grid[i][0] == c) + (grid[i][1] == c) + (grid[i][2] == c);
        dcountr = (grid[i][0] == d) + (grid[i][1] == d) + (grid[i][2] == d);
        ccountc = (grid[0][i] == c) + (grid[1][i] == c) + (grid[2][i] == c);
        dcountc = (grid[0][i] == d) + (grid[1][i] == d) + (grid[2][i] == d);

        if (ccountr + dcountr == 3 && ccountr && dcountr ||
            ccountc + dcountc == 3 && ccountc && dcountc) {
          ++(c == d ? single : two);
          done = true;
        }
      }

      ccountr = (grid[0][0] == c) + (grid[1][1] == c) + (grid[2][2] == c);
      dcountr = (grid[0][0] == d) + (grid[1][1] == d) + (grid[2][2] == d);
      ccountc = (grid[2][0] == c) + (grid[1][1] == c) + (grid[0][2] == c);
      dcountc = (grid[2][0] == d) + (grid[1][1] == d) + (grid[0][2] == d);

      if (!done && ccountr + dcountr == 3 && ccountr && dcountr) {
        ++(c == d ? single : two);
      } else if (!done && ccountc + dcountc == 3 && ccountc && dcountc) {
        ++(c == d ? single : two);
      }
    }
  }
  cout << single << '\n' << two;
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

#define PROBLEM_NAME "tttt"

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
