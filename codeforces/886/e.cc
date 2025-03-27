#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

template <typename T>
[[nodiscard]] static T MIN() {
  return std::numeric_limits<T>::min();
}

template <typename T>
[[nodiscard]] static T MAX() {
  return std::numeric_limits<T>::max();
}

template <typename T>
[[nodiscard]] static T sc(auto&& x) {
  return static_cast<T>(x);
}

template <typename T>
[[nodiscard]] static T sz(auto&& x) {
  return static_cast<T>(x.size());
}

#define prln(...) std::println(__VA_ARGS__)
#define pr(...) std::print(__VA_ARGS__)

#ifdef LOCAL
#define dbgln(...) std::println(__VA_ARGS__)
#define dbg(...) std::print(__VA_ARGS__)
#endif

inline static void NO() {
  prln("NO");
}

inline static void YES() {
  prln("YES");
}

using ll = long long;
using ld = long double;
template <typename T>
using ve = std::vector<T>;
template <typename T, size_t N>
using ar = std::array<T, N>;
template <typename T1, typename T2>
using pa = std::pair<T1, T2>;
template <typename... Ts>
using tu = std::tuple<Ts...>;
template <typename... Ts>
using dq = std::deque<Ts...>;
template <typename... Ts>
using qu = std::queue<Ts...>;
template <typename... Ts>
using pq = std::priority_queue<Ts...>;
template <typename... Ts>
using st = std::stack<Ts...>;
auto lb = [](auto... args) {
  return std::lower_bound(args...);
};
auto ub = [](auto... args) {
  return std::upper_bound(args...);
};

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
//  }}}

void solve() {
  ll n, c;
  cin >> n >> c;
  ll sum = 0, sumsq = 0;
  ll s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    sum += s;
    sumsq += s * s;
  }

  ld C = sumsq - c;

  ld A = 4 * n;
  // NOTE: tbh, look back at solutions,m not sure what went exactly wrong here.
  // most definitely just not taking my time
  // NOTE: didn't check WHY round down/why is this right, just that it *looked* right in the examples
  // this logic is a surefire way to skip certainty and absolutely confuse yourself

  ld B = 4 * sum;

  ll root = (-B + sqrtl(B * B - 4 * A * C)) / (2 * A);
  prln("{}", root);

  // NOTE: tbh, look back at solutions,m not sure what went exactly wrong here.
  // most definitely just not taking my time
  // NOTE: didn't check WHY round down/why is this right, just that it *looked* right in the examples
  // this logic is a surefire way to skip certainty and absolutely confuse yourself

  /*
     p ez, if anything should've just been locked and written the equation
     division and long double - fucked

     say paintings are a, b, c

     ax^2+bx+c

     area c= (a + 2w) ^ 2 + ...
    =a^2+4w^2+4aw + ...

     c = a^2+b^2+...+4(a+b+...) * w + 4nw^2
     0 = sumsq - c


     a^2+b^2+c^2=sum of painting area
     (a+2w)^2+(b+2w)^2+...= c; find w quickly

      a^2+2aw+4w^2+...

      c = = a^2 + 4w^2+2aw + ...
      =a^2+b^2+c^2 + ... 2aw + 2bw + 2cw + ... + 4nw^2
      0 = sumsq + 4nw^2 + 2w(a+b+c+d+....) - c
      quadratic formula
      = 4nw^2+2w(a+b+c+d)
      = 4nw^2+2w(a+b+...) - c +a^2+b^2+c^2+...
     */
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
// }}}
