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
  u32 n;
  cin >> n;

  vec<vec<u32>> tree(n + 1);
  u32 parent;
  for (u32 i = 1; i <= n - 1; ++i) {
    cin >> parent;
    tree[parent].push_back(i + 1);
  }

  string coloring;
  cin >> coloring;

  u32 ans = 0;

  vec<u32> black(n + 1, 0), white(n + 1, 0);

  auto dfs = [&](auto&& self, u32 u, u32 par) -> void {
    white[u] = coloring[u - 1] == 'W';
    black[u] = coloring[u - 1] == 'B';

    for (auto v : tree[u]) {
      if (v == par)
        continue;
      self(self, v, u);

      white[u] += white[v];
      black[u] += black[v];
    }

    if (white[u] == black[u]) {
      ++ans;
    }

    return;
  };

  dfs(dfs, 1, 1);

  println("{}", ans);
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  u32 tc = 1;
  cin >> tc;

  for (u32 t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
