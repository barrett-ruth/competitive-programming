#include <bits/stdc++.h>  // {{{

#include <algorithm>

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

bitset<50 * 50 + 1> visited;

void solve() {
  const i32 dr8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  const i32 dc8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  u32 n, m;
  cin >> n >> m;
  vec<string> g(n);
  for (auto& s : g)
    cin >> s;
  vec<vec<u32>> vis(n, vec<u32>(m, 0));
  bool ok = true;
  for (i32 r = 0; r < (i32)n && ok; ++r)
    for (i32 c = 0; c < (i32)m && ok; ++c)
      if (g[r][c] == '*' && !vis[r][c]) {
        vec<pair<i32, i32>> comp;
        vec<pair<i32, i32>> q = {{r, c}};
        vis[r][c] = 1;
        for (i32 qi = 0; qi < (i32)q.size(); ++qi) {
          auto [x, y] = q[qi];
          comp.push_back({x, y});
          for (i32 d = 0; d < 8; ++d) {
            i32 nx = x + dr8[d], ny = y + dc8[d];
            if (0 <= nx && nx < (i32)n && 0 <= ny && ny < (i32)m &&
                g[nx][ny] == '*' && !vis[nx][ny]) {
              vis[nx][ny] = 1;
              q.push_back({nx, ny});
            }
          }
        }
        if (comp.size() != 3) {
          ok = false;
          break;
        }
        vec<i32> rows, cols;
        for (auto [x, y] : comp) {
          rows.push_back(x);
          cols.push_back(y);
        }
        sort(rows.begin(), rows.end());
        rows.erase(unique(rows.begin(), rows.end()), rows.end());
        sort(cols.begin(), cols.end());
        cols.erase(unique(cols.begin(), cols.end()), cols.end());
        if (rows.size() != 2 || cols.size() != 2) {
          ok = false;
          break;
        }
        i32 cnt = 0;
        for (i32 i = 0; i < 2; ++i)
          for (i32 j = 0; j < 2; ++j)
            for (auto [x, y] : comp)
              if (x == rows[i] && y == cols[j])
                ++cnt;
        if (cnt != 3) {
          ok = false;
          break;
        }
      }
  if (ok)
    YES();
  else
    NO();
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
