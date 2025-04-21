#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using d64 = double;
using d128 = long double;
template <typename T>
using vec = std::vector<T>;
template <typename T, size_t N>
using arr = std::array<T, N>;
template <typename T1, typename T2>
using pai = std::pair<T1, T2>;

template <typename T>
constexpr T MIN = std::numeric_limits<T>::min();

template <typename T>
constexpr T MAX = std::numeric_limits<T>::max();

template <typename T>
[[nodiscard]] static T sc(auto&& x) {
  return static_cast<T>(x);
}

template <typename T>
[[nodiscard]] static T sz(auto&& x) {
  return static_cast<T>(x.size());
}

static void NO() {
  std::cout << "No\n";
}

static void YES() {
  std::cout << "Yes\n";
}

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#ifdef LOCAL
#define db(...) std::print(__VA_ARGS__)
#define dbln(...) std::println(__VA_ARGS__)
#else
#define db(...)
#define dbln(...)
#endif
//  }}}

void solve() {
  u32 n;
  string s;
  cin >> n >> s;

  i64 cols = -1;
  for (u32 i = 0; i < n; ++i) {
    if (s[i] == '0') {
      cols = i - 1;
      break;
    }
  }

  if (cols == -1) {
    if (n == 4)
      YES();
    else
      NO();
    return;
  }

  // NOTE: didn't check it was square, holy shit throw
  if (cols == 0 || n % cols != 0 || cols * cols != n) {
    NO();
    return;
  }

  vec<vec<char>> board(n / cols, vec<char>(cols));
  for (u32 i = 0; i < board.size(); ++i) {
    for (u32 j = 0; j < board[i].size(); ++j) {
      board[i][j] = s[i * cols + j];
    }
  }

  u32 zeroes = 0;
  for (auto c : s)
    if (c == '0')
      ++zeroes;
  for (u32 i = 0; i < cols; ++i) {
    if (s[i] == '0' || s[n - cols + i] == '0') {
      NO();
      return;
    }
  }
  for (u32 i = 0; i < n; i += cols) {
    if (s[i] == '0' || s[i + cols - 1] == '0') {
      NO();
      return;
    }
  }

  if (n - 2 * cols - 2 * (n / cols) + 4 != zeroes) {
    NO();
  } else {
    YES();
  }
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  int tc = 1;
  cin >> tc;

  for (int t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
