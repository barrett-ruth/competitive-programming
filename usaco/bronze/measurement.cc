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
  u32 n;
  cin >> n;
  map<u32, array<i32, 3>> deltas;

  u32 day;
  string name;
  i32 delta;
  for (u32 i = 0; i < n; ++i) {
    cin >> day >> name >> delta;

    if (name[0] == 'M') {
      deltas[day][0] = delta;
    } else if (name[0] == 'E') {
      deltas[day][1] = delta;
    } else {
      deltas[day][2] = delta;
    }
  }

  u32 last_winners = 0b111;
  vector<i64> vals(3, 0);
  i64 ans = 0;
  for (auto it = deltas.begin(); it != deltas.end(); ++it) {
    for (u32 j = 0; j < 3; ++j) {
      vals[j] += it->second[j];
    }
    i64 large = *max_element(all(vals));
    u32 winners = 0b000;
    for (u32 j = 0; j < 3; ++j) {
      winners |= u32(vals[j] == large) << j;
    }

    ans += last_winners != winners;
    last_winners = winners;
  }
  cout << ans << '\n';
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

#define PROBLEM_NAME "measurement"

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
