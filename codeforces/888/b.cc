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
  int n;
  cin >> n;
  ve<int> odds, evens, odd_is, even_is;

  int x;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    if (x & 1) {
      odds.eb(x);
      odd_is.eb(i);
    } else {
      evens.eb(x);
      even_is.eb(i);
    }
  }

  sort(all(evens));
  sort(all(even_is));
  sort(all(odds));
  sort(all(odd_is));

  int e = 0, o = 0;
  int last = 0;
  for (int i = 0; i < n; ++i) {
    if (e < sz<int>(even_is) && even_is[e] == i) {
      if (i && evens[e] < last) {
        NO();
        return;
      }
      last = evens[e];
      ++e;
    } else {
      if (i && odds[o] < last) {
        NO();
        return;
      }
      last = odds[o];
      ++o;
    }
  }

  YES();
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
