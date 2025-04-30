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

vector<pair<i32, i32>> trace(251);

void solve() {
  /*
     - # cows patient 0
     - k bounds

     1. sort by time to "sim" interactions

    - say x and y shake; unless wek one is sick, wedk consequences
    (i.e. who gets sick)
    - only ONE starts out

    - guess ONE cow is patient zero, run sim
    - guess all k from 0 to 251?, taking min of low bound, max of high bound

    k = 250 -> infinity
     bsearch <- no (if can achieve state w/ k=i, doesn't mean k=i-1, nor k=i+1)

NOTE: only candidates for patient zero are initial set 0s, since cows stay sick
     */

  u32 n, t;
  cin >> n >> t;
  string state;
  cin >> state;
  state = '0' + state;

  u32 t_;
  for (u32 i = 0; i < t; ++i) {
    cin >> t_;
    cin >> trace[t_].ff >> trace[t_].ss;
    // NOTE: forgot the one-indexin
  }

  u32 lb = numeric_limits<u32>::max(), ub = 0;
  u32 count = 0;

  /*


     a bunch of cows shake hooves because the gay USACO (usa computing olympiad)
     just decided to theme everything cows

     and for some K, a cow can only transmit what you have (STDs)
     after at most K hooveshakes

     but i misread it as saying that if they contract what you have (an STD)
     they can only transmit the STD up to K days later
     not after they have sex k times (which is what you do, let k approach
     infinity)

     ok. then, after that, i missed k=0 basecase
     then, after that
     basically, i only counted when someone transmitted an std & infecting someone
     instead, i should've counted the cow having sex with ANYONE, even if they already 
     have an std, it still counts as a handshake

     core note: once realize wrong, reexamine entire problem solution (has rpercussions) rather than what u see is wrong
     */

  for (u32 i = 1; i <= n; ++i) {
    bool zero = false;
    for (u32 k = 0; k <= 250; ++k) {
      vector<u32> shakes(n + 1, 0);
      string cur_state(n + 1, '0');
      cur_state[i] = '1';

      for (t_ = 1; t_ <= 250; ++t_) {
        auto [a, b] = trace[t_];
        if (a == 0) {
          continue;
        }

        if (cur_state[a] == '1') {
          ++shakes[a];
        }
        if (cur_state[b] == '1') {
          ++shakes[b];
        }
        if (cur_state[a] == '0' && cur_state[b] == '1' && shakes[b] <= k) {
          cur_state[a] = '1';
        } else if (cur_state[b] == '0' && cur_state[a] == '1' &&
                   shakes[a] <= k) {
          cur_state[b] = '1';
        }
      }

      if (cur_state == state) {
        zero = true;
        lb = min(lb, k);
        ub = max(ub, k);
      }
    }
    count += zero;
  }

  cout << count << ' ' << lb << ' ' << (ub == 250 ? "Infinity" : to_string(ub))
       << '\n';
}

int main() { // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

#define PROBLEM_NAME "tracing"

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
