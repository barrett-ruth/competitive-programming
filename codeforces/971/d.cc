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

template <typename... Args>
void dbgln(std::string const &str, Args &&...args) {
  dbg(str, std::forward<Args>(args)...);
  cout << '\n';
}

template <typename T>
void dbgln(T const &t) {
  dbg("{}\n", t);
}

void prllln() {
  std::cout << '\n';
}

template <typename T>
constexpr T MIN = std::numeric_limits<T>::min();

template <typename T>
constexpr T MAX = std::numeric_limits<T>::min();

#define ff first
#define ss second
#define eb emplace_back
#define ll long long
#define ld long double
#define vec vector
#define endl '\n'

#define all(x) (x).begin(), (x).end()
#define rall(x) (r).rbegin(), (x).rend()
#define sz(x) static_cast<ll>((x).size())
#define FOR(a, b, c) for (ll(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (ll(a) = (b); (a) > (c); --(a))

std::random_device rd;
std::mt19937 gen(rd());

void YES() {
  cout << "YES\n";
}

void NO() {
  cout << "NO\n";
}

constexpr auto N_MAX = (2 * 100000) + 1;
bitset<N_MAX> y_one, y_zero;

void solve() {
  ll n;
  cin >> n;
  y_one.reset();
  y_zero.reset();
  FOR(i, 0, n) {
    ll x, y;
    cin >> x >> y;
    y_one[x] = y_one[x] | (y == 1);
    y_zero[x] = y_zero[x] | (y == 0);
  }

  ll ans = 0;
  FOR(x, 0, n + 1) {
    if (y_one[x] && y_zero[x])
      ans += n - 2;
    if (x >= 1 && x < n && y_one[x] && y_zero[x - 1] && y_zero[x + 1])
      ++ans;
    if (x >= 1 && x < n && y_zero[x] && y_one[x - 1] && y_one[x + 1])
      ++ans;
  }

  dbgln(ans);
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  ll t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
