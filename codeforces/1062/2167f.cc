#include <algorithm>
#include <iostream>
#include <print>
#include <set>
#include <vector>

using namespace std;
using u32 = uint32_t;
using i32 = int32_t;
using u64 = uint64_t;
using i64 = int64_t;

void solve() {
  u32 n;
  i64 k;
  cin >> n >> k;
  vector<vector<u32>> tree(n + 1);
  for (u32 i = 0; i < n - 1; ++i) {
    u32 u, v;
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }

  u64 ans = 0;

  vector<i64> size(n + 1, 0);
  auto dfs = [&](auto &&self, u32 u, u32 par) -> i64 {
    i64 ss = 1;
    for (auto &v : tree[u]) {
      if (v == par) {
        continue;
      }
      ss += self(self, v, u);
    }

    return size[u] = ss;
  };

  dfs(dfs, 1, 0);
  i64 count =
      count_if(begin(size), end(size), [&k](auto const &e) { return e >= k; });

  auto dfs2 = [&](auto &&self, u32 u, u32 par, i64 count) -> void {
    ans += count;

    for (auto v : tree[u]) {
      if (v == par) {
        continue;
      }

      auto su = size[u], sv = size[v];
      size[u] = su - sv;
      size[v] = n;

      i64 child_count = count + (size[u] >= k) - (sv >= k);
      self(self, v, u, child_count);

      size[u] = su;
      size[v] = sv;
    }
  };

  dfs2(dfs2, 1, 0, count);

  println("{}", ans);
}

int main() { // {{{
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

