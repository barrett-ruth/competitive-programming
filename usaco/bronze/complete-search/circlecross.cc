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
  string s;
  cin >> s;
  array<pair<u32, u32>, 26> enter_exit{};
  for (u32 i = 0; i < s.size(); ++i) {
    u32 j = s[i] - 'A';
    if (enter_exit[j].ff == 0) {
      enter_exit[j].ff = i + 1;
    } else {
      enter_exit[j].ss = i + 1;
    }
  }

  u32 ans = 0;
  for (u32 r = 0; r < enter_exit.size(); ++r) {
    for (u32 l = 0; l < r; ++l) {
      if (enter_exit[l].ff < enter_exit[r].ff &&
              enter_exit[r].ff < enter_exit[l].ss &&
              enter_exit[l].ss < enter_exit[r].ss ||
          enter_exit[r].ff < enter_exit[l].ff &&
              enter_exit[l].ff < enter_exit[r].ss &&
              enter_exit[r].ss < enter_exit[l].ss) {
        ++ans;
      }
    }
  }

  cout << ans << '\n';
}

int main() { // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

#define PROBLEM_NAME "circlecross"

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
