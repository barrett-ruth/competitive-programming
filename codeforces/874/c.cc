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
  ve<ll> a(n);
  ll smallest_even = MAX<ll>(), smallest_odd = MAX<ll>();
  for (auto& e : a) {
    cin >> e;
    if (e & 1) {
      smallest_odd = min(smallest_odd, e);
    } else {
      smallest_even = min(smallest_even, e);
    }
  }

  // try even, then odd

  bool bad = false;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      continue;
    }  // odd, make even by sub odd
    if (smallest_odd == MAX<ll>()) {
      bad = true;
      break;
    }
    if (a[i] - smallest_odd > 0) {
      continue;
    } else {
      bad = true;
      break;
    }
  }

  if (!bad) {
    YES();
    return;
  }

  // NOTE: forgt to reset this, use dbgln and braces
  bad = false;
  for (int i = 0; i < n; ++i) {
    if (a[i] & 1) {
      continue;
    }
    if (smallest_odd == MAX<ll>()) {
      bad = true;
      break;
    }
    if (a[i] - smallest_odd > 0) {
      continue;
    } else {
      bad = true;
      break;
    }
  }

  if (bad)
    NO();
  else
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
