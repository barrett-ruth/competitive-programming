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

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
//  }}}

void solve() {
  int n, m, h;
  cin >> n >> m >> h;
  unordered_set<int> horses;

  int horse;
  for (int i = 0; i < h; ++i) {
    cin >> horse;
    horses.insert(horse);
  }

  ve<ve<pa<int, ll>>> graph(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    graph[u].eb(v, w);
    graph[v].eb(u, w);
  }

  ve<ll> marian(n + 1, MAX<ll>()), robin(n + 1, MAX<ll>());

  auto djikstra = [&](int start, ve<ll>& delta) {
    priority_queue<tuple<ll, int, bool>, ve<tuple<ll, int, bool>>, greater<>>
        pq;
    delta[start] = 0;
    pq.emplace(delta[start], start, horses.contains(start));
    unordered_set<int> seen;

    while (!pq.empty()) {
      auto [d0, u, took] = pq.top();
      pq.pop();
      if (d0 > delta[u] && !took) continue;
      if (took) seen.insert(u);
      for (auto [v, w] : graph[u]) {
        ll d1 = d0 + (took ? w / 2 : w);
        bool take = took || horses.contains(v);
        if (d1 < delta[v]) {
          delta[v] = d1;
          pq.emplace(d1, v, take);
        }
      }
    }
  };

  djikstra(1, marian);
  djikstra(n, robin);

  ll ans = MAX<ll>();
  for (int node = 1; node <= n; ++node) {
    ans = min(ans, max(marian[node], robin[node]));
  }

  prln("{}", ans == MAX<ll>() ? -1 : ans);
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
