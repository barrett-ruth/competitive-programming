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

template <typename... Args>
void pr(std::format_string<Args...> fmt, Args&&... args) {
  std::print(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void pr(std::format_string<Args...> fmt) {
  std::print(fmt);
}

template <typename... Args>
void prln(std::format_string<Args...> fmt, Args&&... args) {
  std::println(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void prln(std::format_string<Args...> fmt) {
  std::println(fmt);
}

using ll = long long;
using ld = long double;
template <typename T>
using vec = std::vector<T>;

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define FORI(a, b, c) for (int a = (b); a < (c); ++a)
#define ROFI(a, b, c) for (int a = (b); a > (c); --a)
#define FORLL(a, b, c) for (ll a = (b); a < (c); ++a)
#define ROFLL(a, b, c) for (ll a = (b); a > (c); --a)  // }}}

void solve() {
  int n, k;
  cin >> n >> k;

  vec<pair<ll, ll>> recs;
  FORI(i, 0, n) {
    cin >> recs[i].ff >> recs[i].ss;
  }

  vec<vec<ll>> dp(n + 1, vec<ll>(k + 1, MAX<ll>));
  FORI(i, 0, n + 1) {
    dp[i][0] = 0;
  }

  FORLL(i, 1, n + 1) {
    FORLL(j, 1, k + 1) {
      int x = recs[i - 1].ff, y = recs[i - 1].ss;
      int cost = 0;
      FORLL(take, 0, min(j, recs[i - 1].ff + recs[i - 1].ss) + 1) {
        if (dp[i - 1][j - take] != MAX<ll>)
          dp[i][j] = min(dp[i][j], dp[i - 1][j - take] + cost);
        if (x > y)
          swap(x, y);
        cost += x;
        y--;
      }
    }
  }

  cout << (dp[n][k] == MAX<ll> ? -1 : dp[n][k]) << '\n';
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}  //}}}
