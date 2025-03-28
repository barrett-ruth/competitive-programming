#include <bits/stdc++.h>

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

template <typename... Args>
void dbg(std::string const &str, Args &&...args) {
  std::cout << std::vformat(str, std::make_format_args(args...));
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

void dbgln() {
  std::cout << '\n';
}

template <typename... Args>
void dbgln(std::string const &str, Args &&...args) {
  dbg(str, std::forward<Args>(args)...);
  cout << '\n';
}

template <typename T>
void dbgln(T const &t) {
  dbg(t);
  cout << '\n';
}

template <typename T>
constexpr T MIN = std::numeric_limits<T>::min();

template <typename T>
constexpr T MAX = std::numeric_limits<T>::max();

template <typename T>
static T sc(auto &&x) {
  return static_cast<T>(x);
}

#define ff first
#define ss second
#define eb emplace_back
#define ll long long
#define ld long double
#define vec vector
#define endl '\n'

#define all(x) (x).begin(), (x).end()
#define rall(x) (r).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (int(a) = (b); (a) > (c); --(a))

constexpr int MOD = 998244353;

void solve() {
  ll k, n;
  cin >> k >> n;
  vec<ll> dp(k + 1);
  dp[1] = n;
  for (ll i = 2; i <= k; ++i) {
    ll for_i = (n * (n + 1)) / 2 % MOD;
    dp[i] = for_i;
    for (ll factor = 2; factor < min(k, (ll)floorl(sqrtl(i))) + 1; ++factor) {
      if (i % factor == 0) {
        ll extra = (n * (n + 1) * (n - 1)) / 6 % MOD;
        dp[i] = (dp[i] + extra) % MOD;
        if (factor * factor != i) {
          dp[i] = (dp[i] + extra) % MOD;
        }
      }
    }
  }
  FOR(i, 1, k + 1) {
    cout << dp[i] % MOD << " \n"[i == k];
  }
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
