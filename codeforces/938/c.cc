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
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  vec<ll> a(n);
  for (auto& e : a) {
    cin >> e;
  }

  ll left = ceil(k / 2.0);
  for (int i = 0; i < sz<int>(a) && left > 0; ++i) {
    int take = min(a[i], left);
    a[i] -= take;
    left -= take;
    if (a[i] == 0)
      ++ans;
  }

  ll right = k / 2;

  for (int i = sz<int>(a) - 1; i >= 0 && a[i] > 0 && right > 0; --i) {
    int take = min(a[i], right);
    a[i] -= take;
    right -= take;
    if (a[i] == 0)
      ++ans;
  }

  prln("{}", ans);

  // prln("{} left attacks and {} right", left, right);
  // for (auto x : prefix)
  //   pr("{} ", x);
  // prln();
  // for (auto x : postfix)
  //   pr("{} ", x);
  // prln();

  // ll left_sunk = distance(prefix.begin(), upper_bound(all(prefix), left)) -
  // 1; ll right_sunk =
  //     distance(postfix.begin(), upper_bound(all(postfix), right)) - 1;

  // prln("{} {} {}", left_sunk, right_sunk, left_sunk + right_sunk);
  // prln("{}", left_sunk + right_sunk);
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
