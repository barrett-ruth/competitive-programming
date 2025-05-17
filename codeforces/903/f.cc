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

const u32 MAXN = 2 * 1e5 + 1;
bitset<MAXN> marked, seen;
vector<vector<u32>> tree(MAXN);
deque<u32> q;

void solve() {
  u32 n, k;
  cin >> n >> k;

  marked.reset();
  tree.assign(n + 1, vector<u32>());

  u32 node;
  for (u32 i = 0; i < k; ++i) {
    cin >> node;
    marked[node] = true;
  }

  u32 u, v;
  for (u32 i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    tree[u].emplace_back(v);
    tree[v].emplace_back(u);
  }

  q.clear();
  q.push_back(node);
  seen.reset();
  u32 last = node;

  while (!q.empty()) {
    auto top = q.front();
    q.pop_front();
    seen[top] = true;
    if (marked[top])
      last = top;

    for (auto& neighbor : tree[top]) {
      if (!seen[neighbor]) {
        q.push_back(neighbor);
      }
    }
  }

  q.clear();
  q.push_back(last);
  seen.reset();
  u32 ans = 0, d = 0;

  while (!q.empty()) {
    ++d;
    u32 size = q.size();
    for (u32 i = 0; i < size; ++i) {
      auto top = q.front();
      q.pop_front();
      if (marked[top])
        ans = max(ans, d);
      seen[top] = true;
      for (auto& neighbor : tree[top]) {
        if (!seen[neighbor]) {
          q.push_back(neighbor);
        }
      }
    }
  }

  cout << ans / 2 << endl;
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
