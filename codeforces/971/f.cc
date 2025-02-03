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

void solve() {
  int n, q;
  cin >> n >> q;
  ll A = 0;
  vec<ll> prefix;
  prefix.push_back(0);
  FOR(i, 0, n) {
    ll x;
    cin >> x;
    A += x;
    prefix.push_back(A);
  }

  // TODO: WRITE A BETTER MIN
  // c_k = [a_k, a_k+1, ..., a_n ,a_1, ..., ak-1]
  // [a_2, a_0, a_1]
  // i = 2
  auto shift_sum = [&](int k, int i) -> ll {
    if (i == -1)
      return 0;

    int shifted_i = (i + k) % n;
    if (shifted_i < k) {
      return prefix[n] - prefix[k] + prefix[shifted_i + 1];
    }
    return prefix[shifted_i + 1] - prefix[k];
  };

  FOR(i, 0, q) {
    ll l, r;
    cin >> l >> r;
    --l;
    --r;

    int I = l / n, J = r / n;

    l = l % n, r = r % n;

    ll ans;
    if (I != J)
      ans =
          max(0LL, (J - I - 1) * A) + A - shift_sum(I, l - 1) + shift_sum(J, r);
    else {
      int shifted_l = (l + I) % n;
      int shifted_r = (r + I) % n;

      if (shifted_l <= shifted_r)
        ans = prefix[shifted_r + 1] - prefix[shifted_l];
      else
        ans = prefix[n] - prefix[shifted_l] + prefix[shifted_r + 1];
    }

    dbgln(ans);
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
