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
  ve<pa<ll, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].ff;
    a[i].ss = i;
  }
  sort(all(a));
  ve<ll> prefix(n + 1, 0), postfix(n + 2, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + a[i].ff;
  }
  for (int i = n - 1; i >= 0; --i) {
    postfix[i + 1] = postfix[i + 2] + a[i].ff;
  }

  ve<ll> ans(n);
  for (int i = 0; i < n; ++i) {
    ll x = n + a[i].ff * (i + 1) - prefix[i + 1];
    x += postfix[i + 2] - a[i].ff * (n - i - 1);
    ans[a[i].ss] = x;
  }

  for (auto& e : ans)
    pr("{} ", e);
  prln();
  /*
     1 3 4

     3 + 0 +

     to query @ i, want to get info related to
     a[i] - a[0], a[i] - a[1], ....

     prefix differences + postfix differences for each index

     n + a[i] - a[0] + a[i] - a[1] + ... + a[i] - a[i] + a[j] - a[i] + a[j + 1]
    - a[i]

     = n + a[i] * (i + 1) - prefix[i] (inclusive) + postfix[i] (exclusive) -
    a[i] * ``

     n * a[i] - sum of prefix before i + sum of postfix after i

     sum a[i] - a[j] + 1 for j in range(i + 1)
     count how manny points before us? * a[i]
     remove prefix sum up to j
      - and postfix! <- note this

     *-**
     -
     ---
     ----

     ---
       -
       --

     ----
       --
        -

    really, we're just adding the inclusive distance between ALL pairs


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
