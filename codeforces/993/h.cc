#include <bits/stdc++.h>

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

template <typename... Args>
void dbg(std::string const &str, Args &&...args) {
  std::cout << std::vformat(str,
                            // make_format_args binds arguments to const
                            std::make_format_args(args...));
}

template <typename T>
void dbg(T const &t) {
  std::cout << t;
}

template <std::ranges::range T>
void dbgln(T const &t) {
  if constexpr (std::is_convertible_v<T, char const *>) {
    std::cout << t << '\n';
  } else {
    for (auto const &e : t) {
      std::cout << e << ' ';
    }
    std::cout << '\n';
  }
}

template <typename... Args>
void dbgln(std::string const &str, Args &&...args) {
  dbg(str, std::forward<Args>(args)...);
  cout << '\n';
}

template <typename T>
void dbgln(T const &t) {
  dbg("{}\n", t);
}

void println() {
  std::cout << '\n';
}

template <typename T>
constexpr auto MIN = std::numeric_limits<T>::min();

template <typename T>
constexpr auto MAX = std::numeric_limits<T>::min();

#define ff first
#define ss second
#define eb emplace_back
#define ll long long
#define ld long double
#define vec vector

#define all(x) (x).begin(), (x).end()
#define rall(x) (r).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (int(a) = (b); (a) > (c); --(a))

std::random_device rd;
std::mt19937 gen(rd());

void YES() {
  cout << "YES\n";
}

void NO() {
  cout << "NO\n";
}

void solve() {
  int n, q;
  cin >> n;
  vec<vec<int>> grid(n, vec<int>(n));
  FOR(i, 0, n) {
    FOR(j, 0, n) {
      cin >> grid[i][j];
    }
  }

  vec<vec<int>> dp(n + 1, vec<int>(n + 1, 1));

  while (q--) {
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
  }

  /*

     00 01 02 03 04 05 ...
     10 11 12 13 14 15 ...

     1 * 00 * 2 * 01 + 3 * 02
     4 * 01 + 5 * 

     1 * M[i][j] + 2 * M[i][j + 1] + 3 * M[i][j + 2]
     + 4 * M[i + 1][j] + 5 * M[i + 1][j + 2]

     = sum r0 * n + c0 -> r1 * n + c1

     1 2
     3 4
     5 6

     1 2        0 0
     1 2 +      2 2
     1 2 +      4 4

     3+4^2+8^3+9^4+13^5+14^6

     8+9^2+13^3+14^4 - ( 8^2+9^2+13^2 )
     */
  // FIX: cout

  dbgln("hi");
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
