#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
using f128 = long double;

#if __cplusplus >= 202002L
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
#endif

static void NO() {
  std::cout << "NO\n";
}

static void YES() {
  std::cout << "YES\n";
}

template <typename T>
using vec = std::vector<T>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second

#ifdef LOCAL
#define db(...) std::print(__VA_ARGS__)
#define dbln(...) std::println(__VA_ARGS__)
#else
#define db(...)
#define dbln(...)
#endif
//  }}}

void solve() {
  u32 n, m;
  cin >> n >> m;
  vec<vec<pair<u32, u32>>> graph(n + 1);
  for (u32 i = 0; i < m; ++i) {
    u32 u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }
  vec<u32> s(n + 1);
  for (u32 i = 1; i <= n; ++i)
    cin >> s[i];

  const i64 INF = static_cast<i64>(4e18);
  vec<vec<i64>> dist(n + 1, vec<i64>(1001, INF));
  using T = tuple<i64, u32, u32>;
  priority_queue<T, vec<T>, greater<T>> pq;

  u32 b0 = s[1];
  dist[1][b0] = 0;
  pq.emplace(0, 1, b0);

  while (!pq.empty()) {
    auto [t, u, b] = pq.top();
    pq.pop();
    if (t != dist[u][b])
      continue;
    u32 nb = min(b, s[u]);
    if (nb < b && t < dist[u][nb]) {
      dist[u][nb] = t;
      pq.emplace(t, u, nb);
    }
    for (auto [v, w] : graph[u]) {
      i64 nt = t + static_cast<i64>(w) * static_cast<i64>(b);
      if (nt < dist[v][b]) {
        dist[v][b] = nt;
        pq.emplace(nt, v, b);
      }
    }
  }

  i64 ans = INF;
  for (u32 b = 1; b <= 1000; ++b)
    ans = min(ans, dist[n][b]);
  cout << ans << '\n';
}

int main() {  // {{{
  std::cin.exceptions(std::cin.failbit);

#ifdef LOCAL
  std::cerr.rdbuf(std::cout.rdbuf());
  std::cout.setf(std::ios::unitbuf);
  std::cerr.setf(std::ios::unitbuf);
#else
  std::cin.tie(nullptr)->sync_with_stdio(false);
#endif

  u32 tc = 1;
  std::cin >> tc;

  for (u32 t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
