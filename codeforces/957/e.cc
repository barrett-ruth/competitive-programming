//  {{{
#include <bits/stdc++.h>

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

void prln() {
  std::println();
}

void prln(auto const& t) {
  std::println("{}", t);
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
//  }}}

void solve() {
  int n;
  cin >> n;

  string strn = to_string(n);
  int lenn = sz<int>(strn);

  vec<pair<int, int>> ans;

  for (int a = 1; a <= 100000; ++a) {
    // s =|n|a-b; na-b

    // 1<=|n|a-b<=5
    // b<=|n|a-1    |n|a-5<=b
    int lo = max(1, lenn * a - 5);
    int hi = min(10000, lenn * a - 1);

    for (int b = lo; b <= hi; ++b) {
      int cmp = 0;
      for (int i = 0; i < lenn * a - b; ++i) {
        cmp *= 10;
        cmp += strn[i % lenn] - '0';
      }
      if (cmp == n * a - b) {
        ans.eb(a, b);
      }
    }
  }

  prln("{}", sz<int>(ans));
  for (auto& [a, b] : ans) {
    prln("{} {}", a, b);
  }
}

// {{{
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
// }}}
