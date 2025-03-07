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

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
//  }}}

inline static void NO() {
  prln("NO");
}
inline static void YES() {
  prln("YES");
}

void solve() {
  int n;
  cin >> n;
  ve<int> a(n);
  for (auto& e : a)
    cin >> e;

  ve<int> b(n, 0);
  int write = n - 1;

  int y = 0;
  int i = 0;
  while (i < n) {
    ++y;
    while (i + 1 < n && a[i] == a[i + 1]) {
      ++y;
      ++i;
    }
    if ((b[write] = y) != a[write]) {
      NO();
      return;
    };
    --write;
    if (i + 1 < n) {
      for (int j = 0; j < a[i] - a[i + 1] - 1; ++j) {
        if ((b[write] = y) != a[write]) {
          NO();
          return;
        }
        --write;
      }
    }
    ++i;
  }

  while (write >= 0) {
    if ((b[write] = y) != a[write]) {
      NO();
      return;
    }
    --write;
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
