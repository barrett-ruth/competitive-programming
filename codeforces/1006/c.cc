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
  ll n, x;
  cin >> n >> x;

  ll cur = 0;

  bool broken = false;
  if (n > 1) {
    cout << 0 << ' ';
  } else {
    cout << x << endl;
    return;
  }
  int a = 0;
  for (int i = 0; i < n - 2; ++i) {
    ++cur;

    if (broken || (cur | x) > x) {
      broken = true;
    }

    if (broken) {
      cout << x;
      a |= x;
    } else {
      cout << cur;
      a |= cur;
    }
    cout << ' ';
  }

  ++cur;

  if (broken) {
    cout << x;
  } else {
    if ((cur | x) <= x && (a | cur) == x) {
      cout << cur;
    } else
      cout << x;
  }
  cout << endl;
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
