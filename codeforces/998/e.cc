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
constexpr T MAX = std::numeric_limits<T>::max();

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
#define FOR(a, b, c) for (int a = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (int a = (b); (a) > (c); --(a))

struct union_find {
 public:
  union_find(size_t n = 0) : par(n + 1), rank(n + 1, 0) {
    for (size_t u = 0; u < n + 1; ++u)
      par[u] = u;
  };

  void join(int u, int v) {
    u = find(u), v = find(v);

    if (u == v)
      return;

    if (rank[u] < rank[v])
      std::swap(u, v);

    if (rank[u] == rank[v])
      ++rank[u];

    par[v] = u;
  }

  int find(int u) {
    if (u != par[u])
      par[u] = find(par[u]);
    return par[u];
  }

  void reset(size_t capacity) {
    par.resize(capacity);
    std::iota(par.begin(), par.end(), 0);
    rank.resize(capacity);
  }

  std::vector<int> par;
  std::vector<int> rank;
};

vec<unordered_set<int>> F, G;
union_find Fuf, Guf;
unordered_set<int> to_erase;

void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;

  F.clear();
  F.resize(n + 1);
  G.clear();
  G.resize(n + 1);

  Fuf.reset(n + 1);
  Guf.reset(n + 1);

  FOR(i, 0, m1) {
    int u, v;
    cin >> u >> v;
    F[u].insert(v);
    F[v].insert(u);
  }

  FOR(i, 0, m2) {
    int u, v;
    cin >> u >> v;
    G[u].insert(v);
    G[v].insert(u);
    Guf.join(u, v);
  }

  int ans = 0;

  FOR(u, 1, n + 1) {
    to_erase.clear();
    for (auto v : F[u]) {
      if (Guf.find(u) != Guf.find(v)) {
        to_erase.insert(v);
        F[v].erase(u);
      }
    }
    ans += to_erase.size();
    for (auto e : to_erase)
      F[u].erase(e);
  }

  FOR(u, 1, n + 1) {
    for (auto v : F[u])
      Fuf.join(u, v);
  }

  FOR(u, 1, n + 1) {
    for (auto v : G[u]) {
      if (Fuf.find(u) != Fuf.find(v)) {
        ++ans;
        Fuf.join(u, v);
      }
    }
  }

  dbgln(ans);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
