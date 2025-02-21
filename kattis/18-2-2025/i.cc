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

#ifdef LOCAL
#define dbgln(...) prln(...)
#define dbg(...) pr(...)
#endif

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
  int n;
  cin >> n;
  vec<ld> a(n);
  for (auto& e : a)
    cin >> e;

  ld ans = 0.0;

  ld prefix = 0;
  for (int i = 0; i < n; ++i) {
    prefix += a[i];
    ans = max(ans, prefix / (i + 1));
  }

  ld suffix = 0;
  for (int i = n - 1; i >= 0; --i) {
    suffix += a[i];
    ans = max(ans, suffix / (n - i));
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
