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
#else
#define dbgln(...)
#define dbg(...)
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
  int n, q;
  cin >> n >> q;
  ve<ll> a(n), dsum(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    int x = a[i];
    while (x > 0) {
      dsum[i] += x % 10;
      x /= 10;
    }
  }
  char cmd;
  int l, r, x;
  set<pa<int, int>> s;
  while (q--) {
    cin >> cmd;
    if (cmd == '2') {
      cin >> x;
      // NOTE: struggled with bounds here
      auto it = s.lower_bound({x, 0});
      if (it != s.begin())
        --it;
      if (it != s.end() && it->first <= x && it->second >= x)
        prln("{}", dsum[x - 1]);
      else
        prln("{}", x, a[x - 1]);
    } else {
      cin >> l >> r;
      auto it = s.lower_bound({l, r});
      if (it != s.end() && r >= it->first) {
        l = min(l, it->first);
        r = max(r, it->second);
        s.erase(it);
      }
      s.emplace(l, r);
    }
  }
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
