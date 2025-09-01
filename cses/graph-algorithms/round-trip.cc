#include <bits/stdc++.h>  // {{{

#include <version>
#ifdef __cpp_lib_ranges_enumerate
#include <ranges>
namespace rv = std::views;
namespace rs = std::ranges;
#endif

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

  vec<vec<u32>> tree(n + 1);

  for (u32 i = 0; i < m; ++i) {
    u32 u, v;
    cin >> u >> v;

    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  vec<i32> par(n + 1, -1);

  i32 cycle_u = -1, cycle_v = -1;

  auto dfs = [&](auto&& self, u32 u, u32 parent) -> bool {
    for (auto v : tree[u]) {
      if (v == parent) {
        continue;
      }
      if (par[v] != -1) {
        cycle_u = u;
        cycle_v = v;
        return true;
      }

      par[v] = u;

      if (self(self, v, u)) {
        return true;
      }
    }

    return false;
  };

  for (u32 u = 1; u <= n; ++u) {
    if (par[u] != -1) {
      continue;
    }

    par[u] = u;

    if (!dfs(dfs, u, u)) {
      continue;
    }

    vec<i32> ans;
    ans.push_back(cycle_v);
    for (i32 x = cycle_u; x != cycle_v; x = par[x])
      ans.push_back(x);
    ans.push_back(cycle_v);

    cout << ans.size() << '\n';
    for (auto e : ans)
      cout << e << ' ';

    return;
  }

  cout << "IMPOSSIBLE\n";
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
  // std::cin >> tc;

  for (u32 t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
