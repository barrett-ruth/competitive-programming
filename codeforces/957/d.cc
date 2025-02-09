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
  int _, jump, swim;
  cin >> _ >> jump >> swim;
  string s;
  cin >> s;

  int get_to = 0;
  vec<int> logs;
  FORI(i, 0, sz<int>(s)) {
    if (s[i] == 'L')
      logs.pb(i);
  }

  logs.pb(sz<int>(s) + 1);

  int pos = -1;
  bool done = true;
  while (pos < sz<int>(s)) {
    auto diff = logs[get_to] - pos;
    if (jump < diff) {
      if ((pos += jump) < sz<int>(s)) {
        while (pos < sz<int>(s) && pos < logs[get_to]) {
          if (s[pos] == 'C' || swim == 0) {
            done = false;
            break;
          }
          ++pos;
          --swim;
        }
        if (!done)
          break;
      } else
        break;
    } else {
      pos = logs[get_to];
    }
    ++get_to;
  }

  if (done)
    prln("YES");
  else
    prln("NO");
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
