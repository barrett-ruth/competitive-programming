#include <bits/stdc++.h>

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

template <typename... Args>
void dbg(std::string const &str, Args &&...args) {
  std::cout << std::vformat(str, std::make_format_args(args...));
}

template <typename T>
void dbg(T const &t) {
  std::cout << t;
}

template <std::ranges::range T>
void dbgln(T const &t) {
  if constexpr (std::is_convertible_v<T, char const *>) {
    std::cout << t << '\n';
  } else {
    for (auto const &e : t) {
      std::cout << e << ' ';
    }
    std::cout << '\n';
  }
}

void dbgln() {
  std::cout << '\n';
}

template <typename... Args>
void dbgln(std::string const &str, Args &&...args) {
  dbg(str, std::forward<Args>(args)...);
  cout << '\n';
}

template <typename T>
void dbgln(T const &t) {
  dbg(t);
  cout << '\n';
}

template <typename T>
constexpr T MIN = std::numeric_limits<T>::min();

template <typename T>
constexpr T MAX = std::numeric_limits<T>::min();

template <typename T>
static T sc(auto &&x) {
  return static_cast<T>(x);
}

#define ff first
#define ss second
#define eb emplace_back
#define ll long long
#define ld long double
#define vec vector
#define endl '\n'

#define all(x) (x).begin(), (x).end()
#define rall(x) (r).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (int(a) = (b); (a) > (c); --(a))

struct union_find {
 public:
  union_find(size_t n) : par(n + 1), rank(n + 1, 0), size(n + 1, 0) {
    std::iota(par.begin(), par.end(), 0);
  };

  void join(int u, int v) {
    u = find(u), v = find(v);

    if (size[u] == 0)
      size[u] = 1;
    if (size[v] == 0)
      size[v] = 1;

    if (u == v)
      return;

    if (rank[u] < rank[v])
      std::swap(u, v);

    if (rank[u] == rank[v]) {
      ++rank[u];
    }
    size[u] += size[v];

    par[v] = u;
  }

  int find(int u) {
    if (u != par[u])
      par[u] = find(par[u]);
    return par[u];
  }

  size_t capacity;
  std::vector<int> par;
  std::vector<int> rank;
  std::vector<int> size;
};

vector<pair<int, int>> dirs;

vec<string> grid;

void solve() {
  int n, m;
  cin >> n >> m;
  vec<bool> seen(n * m + 1, false);

  grid.resize(n);

  union_find uf(m * n);

  auto index = [&m](int r, int c) {
    return r * m + c;
  };

  auto valid = [&](int r, int c) {
    return min(r, c) >= 0 && r < n && c < m;
  };

  FOR(r, 0, n) {
    cin >> grid[r];
  }

  FOR(r, 0, n) {
    FOR(c, 0, m) {
      if (grid[r][c] == '#') {
        uf.join(index(r, c), index(r, c));
        for (auto [dr, dc] : dirs) {
          int nr = r + dr, nc = c + dc;
          if (valid(nr, nc) && grid[nr][nc] == '#') {
            uf.join(index(r, c), index(nr, nc));
          }
        }
      }
    }
  }

  ll ans = 0;

  FOR(r, 0, n) {
    ll cur = 0;
    seen.assign(sz(seen), false);
    FOR(c, 0, m) {
      cur += grid[r][c] == '.';
      if (grid[r][c] == '.') {
      FOR(dr, -1, 2) {
        int nr = r + dr;
        int i;
        if (valid(nr, c) && !seen[i = uf.find(index(nr, c))]) {
          cur += uf.size[i];
          seen[i] = true;
        }
      }
    }
    ans = max(ans, cur);
  }

  FOR(c, 0, m) {
    ll cur = 0;
    seen.assign(sz(seen), false);
    FOR(r, 0, n) {
      cur += grid[r][c] == '.';
      FOR(dc, -1, 2) {
        int nc = c + dc;
        int i;
        if (valid(r, nc) && !seen[i = uf.find(index(r, nc))]) {
          cur += uf.size[i];
          seen[i] = true;
        }
      }
    }
    ans = max(ans, cur);
  }

  dbgln(ans);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  dirs.emplace_back(1, 0);
  dirs.emplace_back(-1, 0);
  dirs.emplace_back(0, 1);
  dirs.emplace_back(0, -1);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
