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
[[nodiscard]] static T sc(auto&& x) {
  return static_cast<T>(x);
}

template <typename T>
[[nodiscard]] static T sz(auto&& x) {
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
  string line;
  vec<ll> lengths;
  while (getline(cin, line)) {
    lengths.eb(sz<ll>(line));
  }

  ll ans = 0;
  ll large = *max_element(all(lengths));
  lengths.pop_back();
  for (auto l : lengths) {
    ans += (large - l) * (large - l);
  }

  cout << ans << endl;
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
