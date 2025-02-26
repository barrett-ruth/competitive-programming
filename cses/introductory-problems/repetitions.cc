#include <bits/stdc++.h> // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

template <typename T> constexpr T MIN = std::numeric_limits<T>::min();

template <typename T> constexpr T MAX = std::numeric_limits<T>::max();

template <typename T> [[nodiscard]] static T sc(auto &&x) {
  return static_cast<T>(x);
}

template <typename T> [[nodiscard]] static T sz(auto &&x) {
  return static_cast<T>(x.size());
}

using ll = long long;
using ld = long double;
template <typename T> using vec = std::vector<T>;
template <typename T, size_t N> using arr = std::array<T, N>;

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
//  }}}

void solve() {
  string s;
  cin >> s;

  ll streak = 0, ans = 0;
  char last = ' ';
  for (auto c : s) {
    if (last == ' ' || last == c) {
      ++streak;
      ans = max(ans, streak);
    } else {
      streak = 1;
    }
    last = c;
  }
  cout << ans << endl;
}

int main() { // {{{
  cin.tie(nullptr)->sync_with_stdio(false);

  solve();

  return 0;
}
// }}}
