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

struct Cow {
  u32 i;
  i64 x, y;
};

void solve() {
  u32 n;
  cin >> n;

  vector<Cow> east_cows, north_cows;
  vector<i64> ans(n, -1);

  char dir;
  i64 x, y;
  for (u32 i = 0; i < n; ++i) {
    cin >> dir >> x >> y;

    Cow cow{i, x, y};
    if (dir == 'E') {
      east_cows.emplace_back(cow);
    } else {
      north_cows.emplace_back(cow);
    }
  }

  sort(all(east_cows), [](auto const& c1, auto const& c2) {
    return c1.y < c2.y;
  });
  sort(all(north_cows), [](auto const& c1, auto const& c2) {
    return c1.x < c2.x;
  });

  for (auto& nc : north_cows) {
    for (auto& ec : east_cows) {
      if (ec.x > nc.x || nc.y >= ec.y || ans[ec.i] != -1)
        continue;

      auto et = nc.x - ec.x;
      auto nt = ec.y - nc.y;

      if (nt < et) {
        ans[ec.i] = et;
      }
      if (et < nt) {
        ans[nc.i] = nt;
        break;
      }
    }
  }

  for (auto& e : ans) {
    if (e == -1) {
      cout << "Infinity";
    } else {
      cout << e;
    }
    cout << '\n';
  }
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

#define PROBLEM_NAME "rut"

#ifdef LOCAL
  freopen("io/" PROBLEM_NAME ".in", "r", stdin);
  freopen("io/" PROBLEM_NAME ".out", "w", stdout);
#endif

  solve();

  return 0;
}
// }}}
