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

bitset<2 * 100000 + 5 + 1> used;
vec<int> I;

void solve() {
  ll n, x;
  cin >> n >> x;
  vec<ll> a(n);
  for (auto& e : a)
    cin >> e;

  used.reset();
  I = {1};

  ll ans = 1;

  for (auto number : a) {
    if (x % number)
      continue;
    vec<int> nxt;
    for (auto i : I) {
      if (i * number >= sz<ll>(used))
        continue;
      if (i * number == x) {
        ++ans;
        used.reset();
        used[number] = true;
        I.clear();
        nxt = {1};
        nxt.pb(number);
        break;
      }
      if (!used[i * number]) {
        nxt.pb(i * number);
        used[i * number] = true;
      }
    }
    I.insert(I.end(), all(nxt));
  }

  prln("{}", ans);
}

// {{{
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  ll t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
// }}}
