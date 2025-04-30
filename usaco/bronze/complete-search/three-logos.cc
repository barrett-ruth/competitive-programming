#include <bits/stdc++.h> // {{{

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

#if __cplusplus >= 202002L
template <typename T> constexpr T MIN = std::numeric_limits<T>::min();

template <typename T> constexpr T MAX = std::numeric_limits<T>::max();

template <typename T> [[nodiscard]] static T sc(auto &&x) {
  return static_cast<T>(x);
}

template <typename T> [[nodiscard]] static T sz(auto &&x) {
  return static_cast<T>(x.size());
}
#endif

static void NO() { std::cout << "NO\n"; }

static void YES() { std::cout << "YES\n"; }

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

void print(u32 n, u32 x1, u32 y1, u32 x2, u32 y2, u32 x3, u32 y3) {
  vector<vector<char>> board(n, vector<char>(n, '.'));

  for (u32 i = 0; i < y1; ++i) {
    for (u32 j = 0; j < x1; ++j) {
      board[i][j] = 'A';
    }
  }

  u32 sr = 0, sc = x1;
  if (x1 == n) {
    sr = y1;
    sc = 0;
  }

  for (u32 i = 0; i < y2; ++i) {
    for (u32 j = 0; j < x2; ++j) {
      board[sr + i][sc + j] = 'B';
    }
  }

  bool done = false;
  for (u32 i = 0; !done && i < n; ++i) {
    for (u32 j = 0; j < n; ++j) {
      if (board[i][j] == '.') {
        sr = i;
        sc = j;
        done = true;
        break;
      }
    }
  }

  for (u32 i2 = 0; i2 < y3; ++i2) {
    for (u32 j2 = 0; j2 < x3; ++j2) {
      board[sr + i2][sc + j2] = 'C';
    }
  }

  cout << n << endl;
  for (const auto &row : board) {
    for (char c : row) {
      cout << c;
    }
    cout << '\n';
  }
}

void solve() {
  u32 x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  u32 area = x1 * y1 + x2 * y2 + x3 * y3;

  if (ceil(sqrt(area)) != floor(sqrt(area))) {
    cout << "-1\n";
    return;
  }

  u32 n = sqrt(area);

  if (x1 != n) {
    swap(x1, y1);
  }

  if (x1 == n) {
    if (y2 + y3 == n) {
      swap(x2, y2);
      swap(x3, y3);
      print(n, x1, y1, x2, y2, x3, y3);
      return;
    } else if (x2 + y3 == n) {
      swap(x3, y3);
      print(n, x1, y1, x2, y2, x3, y3);
      return;
    } else if (y2 + x3 == n) {
      swap(x2, y2);
      print(n, x1, y1, x2, y2, x3, y3);
      return;
    } else if (x2 + x3 == n) {
      print(n, x1, y1, x2, y2, x3, y3);
      return;
    } else if (x2 == n && y2 + y3 == n - y1 || x3 == n && y2 + y3 == n - y1) {
      print(n, x1, y1, x2, y2, x3, y3);
      return;
    } else if (y2 == n && x2 + y3 == n - y1) {
      print(n, x1, y1, y2, x2, x3, y3);
      return;
    } else if (y2 == n && x2 + x3 == n - y1) {
      swap(x2, y2);
      swap(x3, y3);
      print(n, x1, y1, x2, y2, x3, y3);
      return;
    } else if (y3 == n && y2 + x3 == n - y1) {
      print(n, x1, y1, y2, x2, y3, x3);
      return;
    }
  }
  if (x1 + x2 != n) {
    swap(x2, y2);
  }
  if (x1 + x2 == n) {
    if (y1 + y3 != n) {
      swap(x3, y3);
    }
    if (y1 + y3 == n) {
      print(n, x1, y1, x2, y2, x3, y3);
      return;
    }
  }
  if (x1 + x3 != n)
    swap(x3, y3);

  if (x1 + x3 == n) {
    if (y1 + y2 != n) {
      swap(x2, y2);
    }
    if (y1 + y2 == n) {
      print(n, x1, y1, x2, y2, x3, y3);
      return;
    }
  }
  cout << "-1\n";
}

int main() { // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  u32 tc = 1;
  // cin >> tc;

  for (u32 t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
