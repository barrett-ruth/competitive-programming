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

ve<pa<int, int>> dxdy = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

template <typename T>
struct union_find {
 public:
  explicit union_find(size_t capacity)
      : par(capacity, 0), rank(capacity, 0), sums(capacity, 0) {
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

    // NOTE the double counting + joining before collecting value in the union find
    sums[u] += sums[v];

    par[v] = u;
  }

  void insert(T const& u, T const& val) {
    sums[u] = val;
  }

  [[nodiscard]] T find(T const& u) noexcept {
    if (u != par[u])
      par[u] = find(par[u]);
    return par[u];
  }

  std::vector<T> par;
  std::vector<int> rank;
  std::vector<int> sums;
};

void solve() {
  int n, m;
  cin >> n >> m;
  union_find<int> uf(n * m);
  ve<ve<int>> grid(n, ve<int>(m));
  auto index = [&](int r, int c) {
    return r * m + c;
  };
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      cin >> grid[r][c];
      uf.insert(index(r, c), grid[r][c]);
    }
  }
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      if (grid[r][c]) {
        for (auto& [dr, dc] : dxdy) {
          auto nr = r + dr, nc = c + dc;
          if (min(nr, nc) >= 0 && nr < n && nc < m && grid[nr][nc]) {
            uf.join(index(r, c), index(nr, nc));
          }
        }
      }
    }
  }
  prln("{}", *max_element(all(uf.sums)));
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
