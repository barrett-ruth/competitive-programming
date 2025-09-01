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
  vec<i32> par(n + 1, -1);
  par[1] = 1;

  u32 u, v;
  for (u32 i = 0; i < m; ++i) {
    cin >> u >> v;

    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  queue<u32> q{{1}};

  while (!q.empty()) {
    auto node = q.front();
    q.pop();

    for (auto& neighbor : tree[node]) {
      if (par[neighbor] == -1) {
        par[neighbor] = node;
        q.push(neighbor);
      }
    }
  }

  if (par[n] == -1) {
    cout << "IMPOSSIBLE\n";
    return;
  }

  u32 cur = n;
  vec<u32> ans;
  while (cur != 1) {
    ans.push_back(cur);
    cur = par[cur];
  }

  ans.push_back(1);

  reverse(all(ans));

  cout << ans.size() << '\n';
  for (u32 i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " \n"[i == ans.size() - 1];
  }
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
