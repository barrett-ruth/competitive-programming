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
  vector<u32> shell_locs(3), shell_counts(3, 0);
  iota(all(shell_locs), 0);

  u32 n, a, b, g;
  cin >> n;
  for (u32 i = 0; i < n; ++i) {
    cin >> a >> b >> g;

    --a;
    --b;
    --g;
    for (u32 j = 0; j < shell_locs.size(); ++j) {
      if (shell_locs[j] == a)
        shell_locs[j] = b;
      else if (shell_locs[j] == b)
        shell_locs[j] = a;
      shell_counts[j] += shell_locs[j] == g;
    }
  }

  cout << *max_element(all(shell_counts)) << '\n';
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

#define PROBLEM_NAME "shell"

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
