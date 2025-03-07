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
[[nodiscard]] static T sc(auto &&x) {
  return static_cast<T>(x);
}

[[nodiscard]] static int sz(auto &&x) {
  return static_cast<int>(x.size());
}

template <typename... Args>
void pr(std::format_string<Args...> fmt, Args &&...args) {
  std::print(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void prln(std::format_string<Args...> fmt, Args &&...args) {
  std::println(fmt, std::forward<Args>(args)...);
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
#define rall(x) (x).rbegin(), (x).rend()  // }}}

#define FORI(a, b, c) for (int a = (b); a < (c); ++a)
#define ROFI(a, b, c) for (int a = (b); a > (c); --a)
#define FORLL(a, b, c) for (ll a = (b); a < (c); ++a)
#define ROFLL(a, b, c) for (ll a = (b); a > (c); --a)

void solve() {
  string a;
  cin >> a;
  if (!(a.size() > 2)) {
    std::println("NO");
    return;
  }
  if (!(a[0] == '1' && a[1] == '0')) {
    std::println("NO");
    return;
  }

  int x = sz(a);

  if (stoi(a.substr(2, a.size())) < 2 || a[2] == '0') {
    std::println("NO");
  } else {
    std::println("YES");
  }
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
