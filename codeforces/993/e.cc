#include <bits/stdc++.h>

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

template <typename... Args>
void dbg(std::string const &str, Args &&...args) {
  std::cout << std::vformat(str,
                            // make_format_args binds arguments to const
                            std::make_format_args(args...));
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

void println() {
  std::cout << '\n';
}

template <typename T>
constexpr auto MIN = std::numeric_limits<T>::min();

template <typename T>
constexpr auto MAX = std::numeric_limits<T>::min();

#define ff first
#define ss second
#define eb emplace_back
#define ll long long
#define ld long double
#define vec vector

#define all(x) (x).begin(), (x).end()
#define rall(x) (r).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())
#define FOR(a, b, c) for (int a = b; a < c; ++a)

std::random_device rd;
std::mt19937 gen(rd());

void YES() {
  cout << "YES\n";
}

void NO() {
  cout << "NO\n";
}

void solve() {
  ll k, l1, r1, l2, r2;
  cin >> k >> l1 >> r1 >> l2 >> r2;
  /*
     y = k ^ n * x

     x in [l1, r1]; y in [l2, r2]

     y/x=k^n -> n bounded by r2/l1=k^n<-> n=log_k(r2/l1)

     knowing n, let A=k^n
     y=Ax

     left bound = max{l1, ceil(l2/A)}
     right bound = min{r1, floor r2/A}

     ans += right - left
     */

  ll max_n = ceill(log((ld)r2 / l1) / log(k));
  ll A = 1;
  ll ans = 0;

  FOR(_, 0, max_n + 1) {
    ll left = max(l1, (ll)ceill((ld)l2 / A));
    ll right = min(r1, (ll)floorl((ld)r2 / A));

    if (left <= right)
      ans += right - left + 1;

    A *= k;
  }

  cout << ans << '\n';
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
