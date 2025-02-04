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
constexpr T MAX = std::numeric_limits<T>::min();

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

std::random_device rd;
std::mt19937 gen(rd());

long long power(long long base, long long exp) {
  long long result = 1;
  while (exp > 0) {
    if (exp & 1)
      result *= base;
    base *= base;
    exp >>= 1;
  }
  return result;
}

ll log_baseb(ll x, ll b) {
  ll res = 0;
  while (x >= b) {
    x /= b;
    res++;
  }
  return res;
}

ll ceil_log_baseb(ll x, ll base) {
  ll res = 0, power = 1;
  while (power < x) {
    power *= base;
    res++;
  }
  return res;
}

void solve() {
  ll l, r;
  cin >> l >> r;

  ll ans = l == 1 ? 1 : 1 + log_baseb(l, 3);
  if (r - l + 1 > 1)
    ans *= 2;

  // add on count to reduce range [l+1,r] to 0

  ll L = l + 1;

  while (L <= r) {
    ll B = min(r + 1, (ll)power(3, 1 + log_baseb(L, 3)));
    // dbgln("floor(log({})/log(3))={}", L, log_baseb(L, 3));
    // dbgln("L={}, B={}", L, B);
    ans += ceil_log_baseb(B, 3) * (B - L);
    L = B;
  }

  dbgln(ans);
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
