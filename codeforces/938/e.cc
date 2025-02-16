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
  string s;
  cin >> s;

  int ans = 1;

  for (int k = sz<int>(s); k >= 2; --k) {
    string S = s;
    vec<int> toggle(S.size(), 0);

    int cumulative = 0;
    for (int i = 0; i < sz<int>(S) - k; ++i) {
      cumulative += toggle[i];
      int actual = (S[i] - '0') ^ (cumulative & 1);
      if (actual == 0) {
        ++cumulative;
        ++toggle[i + k];
      }
    }

    int zeroes = 0;
    for (int j = sz<int>(S) - k; j < sz<int>(S); ++j) {
      cumulative += toggle[j];
      int actual = (S[j] - '0') ^ (cumulative & 1);
      zeroes += actual == 0;
    }

    if (zeroes == 0 || zeroes == k) {
      ans = k;
      break;
    }
  }

  prln("{}", ans);
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
// }}}
