#include <bits/stdc++.h> // {{{

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
template <typename T> constexpr T MIN = std::numeric_limits<T>::min();

template <typename T> constexpr T MAX = std::numeric_limits<T>::max();

template <typename T> [[nodiscard]] static T sc(auto &&x) {
  return static_cast<T>(x);
}

template <typename T> [[nodiscard]] static T sz(auto &&x) {
  return static_cast<T>(x.size());
}
#endif

static void NO() { std::cout << "NO\n"; }

static void YES() { std::cout << "YES\n"; }

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
  u32 n, B;
  cin >> n >> B;

  vector<pair<u32, u32>> pts(n);
  vector<u32> horiz_placements, vert_placements;

  for (u32 i = 0; i < n; ++i) {
    cin >> pts[i].ff >> pts[i].ss;
    vert_placements.emplace_back(pts[i].ff + 1);
    horiz_placements.emplace_back(pts[i].ss + 1);
  }

  u64 ans = numeric_limits<u64>::max();
  for (auto vp : vert_placements) {
    for (auto hp : horiz_placements) {
      u64 tl = 0, tr = 0, bl = 0, br = 0;
      for (auto &[x, y] : pts) {
        if (x < vp && y > hp)
          ++tl;
        if (x > vp && y > hp)
          ++tr;
        if (x < vp && y < hp)
          ++bl;
        if (x > vp && y < hp)
          ++br;
      }
      ans = min(ans, max({tl, tr, bl, br}));
    }
  }
  cout << ans << '\n';
}

int main() { // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

#define PROBLEM_NAME "balancing"

#ifdef LOCAL
  freopen("io/" PROBLEM_NAME ".in", "r", stdin);
  freopen("io/" PROBLEM_NAME ".out", "w", stdout);
#else
  freopen(PROBLEM_NAME ".in", "r", stdin);
  freopen(PROBLEM_NAME ".out", "w", stdout);
#endif

  solve();

  return 0;
}
// }}}
