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

#if __cplusplus >= 201703L
template <typename T> constexpr T MIN = std::numeric_limits<T>::min();

template <typename T> constexpr T MAX = std::numeric_limits<T>::max();

template <typename T, typename U> [[nodiscard]] T sc(U &&u) {
  return static_cast<T>(std::forward<U>(u));
}

template <typename T, typename C> [[nodiscard]] T sz(C const &c) {
  return static_cast<T>(c.size());
}
#endif

#if defined(LOCAL) && __cplusplus >= 201703L
#define db(...) std::print(__VA_ARGS__)
#define dbln(...) std::println(__VA_ARGS__)
#else
#define db(...)
#define dbln(...)
#endif

static void NO() { std::cout << "NO\n"; }

static void YES() { std::cout << "YES\n"; }

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ff first
#define ss second
//  }}}

struct ac {
  u32 l, r;
  i32 p, m;
  // NOTE: copied from AI - order doesn't matter, just need to consider all
  // permutations
  bool operator<(ac const &o) const {
    return tie(l, r, p, m) < tie(o.l, o.r, o.p, m);
  }
};

void solve() {
  u32 N, M;
  cin >> N >> M;

  vector<i32> to_cool(101, 0);

  u32 l, r, c, m;
  for (u32 i = 0; i < N; ++i) {
    cin >> l >> r >> c;

    for (u32 j = l; j <= r; ++j) {
      to_cool[j] = c;
    }
  }

  vector<ac> acs;
  for (u32 i = 0; i < M; ++i) {
    cin >> l >> r >> c >> m;

    acs.emplace_back(ac{l, r, c, m});
  }

  sort(all(acs));

  u32 ans = MAX<u32>;
  for (u32 mask = 0; mask < 1LL << M; ++mask) {
    u32 tc = MAX<u32>;
    auto temps = to_cool;

    u32 cost = 0;
    // subsets != permutation/order
    // want to track use/lack of use
    for (u32 bit = 0; bit < M; ++bit) {
      if (!(mask & (1 << bit)))
        continue;
      auto &a = acs[bit];
      cost += a.m;
      for (u32 j = a.l; j <= min((u32)100, a.r); ++j) {
        temps[j] -= a.p;
      }
      if (all_of(all(temps), [](i32 e) { return e <= 0; })) {
        ans = min(ans, cost);
        break;
      }
    }

    ans = min(ans, tc);
  }

  cout << ans << endl;
}

int main() { // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

#define PROBLEM_NAME "air-cownditioning-ii"

#ifdef LOCAL
  freopen("io/" PROBLEM_NAME ".in", "r", stdin);
  freopen("io/" PROBLEM_NAME ".out", "w", stdout);
#endif

  solve();

  return 0;
}
// }}}
