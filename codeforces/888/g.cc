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

template <typename T>
struct union_find {
 public:
  explicit union_find(size_t capacity)
      : par(capacity + 1, 0), rank(capacity + 1, 0) {
    std::iota(par.begin(), par.end(), 0);
  };

  void join(T u, T v) noexcept {
    u = find(u), v = find(v);

    if (u == v)
      return;

    if (rank[u] < rank[v])
      std::swap(u, v);

    if (rank[u] == rank[v])
      ++rank[u];

    par[v] = u;
  }

  [[nodiscard]] T find(T const& u) noexcept {
    if (u != par[u])
      par[u] = find(par[u]);
    return par[u];
  }

  std::vector<T> par;
  std::vector<int> rank;
};

void solve() {
  int n, m;
  cin >> n >> m;

  ve<ll> heights(n + 1);
  for (int i = 1; i <= n; ++i)
    cin >> heights[i];

  ve<ar<ll, 3>> roads(m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    if (heights[u] > heights[v]) {
      roads.pb({heights[u] - heights[v], u, v});
    } else {
      roads.pb({heights[v] - heights[v], v, u});
    }
  }

  sort(all(roads));
  union_find<int> uf(n);

  int q;
  cin >> q;
  ve<ar<ll, 5>> queries(q);
  for (int i = 0; i < q; ++i) {
    ll a, b, e;
    cin >> a >> b >> e;
    queries[i] = {heights[a] + e, a, b, e, i};
  }
  sort(all(queries));

  ve<bool> ans(n, false);

  for (auto& [hab, a, b, e, i] : queries) {
    while (i < m && roads[i][0] <= hab && roads[i][1] <= hab) {
      uf.join(a, roads[0][1]);
      uf.join(a, roads[0][2]);
      ++i;
    }

    ans[i] = uf.find(a) == uf.find(b);
  }

  for (auto e : ans) {
    e ? YES() : NO();
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
