#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma gcc optimize("o2,unroll-loops")
#pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

template <typename t>
constexpr t min = std::numeric_limits<t>::min();

template <typename t>
constexpr t max = std::numeric_limits<t>::max();

template <typename t>
[[nodiscard]] static t sc(auto&& x) {
  return static_cast<t>(x);
}

template <typename t>
[[nodiscard]] static t sz(auto&& x) {
  return static_cast<t>(x.size());
}

using ll = long long;
using ld = long double;
template <typename t>
using vec = std::vector<t>;
template <typename t, size_t n>
using arr = std::array<t, n>;

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
//  }}}

void solve() {
  string s;
  string problem = "problem";
  while (getline(cin, s)) {
    transform(all(s), s.begin(), [](char c) {
      return std::tolower(c);
    });

    cout << (s.find(problem) != string::npos ? "yes" : "no") << endl;
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
