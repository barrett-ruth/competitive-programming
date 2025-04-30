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

static void NO() {
  std::cout << "NO\n";
}

static void YES() {
  std::cout << "YES\n";
}

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
  i32 n, m;
  cin >> n >> m;

  vector<pair<i32, i32>> limit(n), cow(m);
  for (u32 i = 0; i < n; ++i) {
    cin >> limit[i].ff >> limit[i].ss;
    if (i)
      limit[i].ff += limit[i - 1].ff;
  }
  for (u32 i = 0; i < m; ++i) {
    cin >> cow[i].ff >> cow[i].ss;
    if (i)
      cow[i].ff += cow[i - 1].ff;
  }

  i32 i = -1, j = -1;

  i32 ans = 0;
  while (j < m) {
    if (i == -1) {
      ++i;
      ++j;
    } else if (i + 1 < n && limit[i + 1].ff <= cow[j].ff) {
      ++i;
    } else {
      ++j;
    }
    ans = max(ans, cow[j].ss - limit[i].ss);
  }
  cout << ans << '\n';
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

#define PROBLEM_NAME "speeding"

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
