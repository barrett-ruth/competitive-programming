#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

template <typename T>
[[nodiscard]] static T MIN() {
  return std::numeric_limits<T>::min();
}

template <typename T>
[[nodiscard]] static T MAX() {
  return std::numeric_limits<T>::max();
}

template <typename T>
[[nodiscard]] static T sc(auto&& x) {
  return static_cast<T>(x);
}

template <typename T>
[[nodiscard]] static T sz(auto&& x) {
  return static_cast<T>(x.size());
}

#define prln(...) std::println(__VA_ARGS__)
#define pr(...) std::print(__VA_ARGS__)

#ifdef LOCAL
#define dbgln(...) std::println(__VA_ARGS__)
#define dbg(...) std::print(__VA_ARGS__)
#endif

inline static void NO() {
  prln("NO");
}

inline static void YES() {
  prln("YES");
}

using ll = long long;
using ld = long double;
template <typename T>
using ve = std::vector<T>;
template <typename T, size_t N>
using ar = std::array<T, N>;
template <typename T1, typename T2>
using pa = std::pair<T1, T2>;
template <typename... Ts>
using tu = std::tuple<Ts...>;
template <typename... Ts>
using dq = std::deque<Ts...>;
template <typename... Ts>
using qu = std::queue<Ts...>;
template <typename... Ts>
using pq = std::priority_queue<Ts...>;
template <typename... Ts>
using st = std::stack<Ts...>;
auto lb = [](auto... args) {
  return std::lower_bound(args...);
};
auto ub = [](auto... args) {
  return std::upper_bound(args...);
};

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
//  }}}

constexpr static ll MOD = 998244353;

void solve() {
  int n, m;
  ld d;
  cin >> n >> m >> d;
  ll d_squared = ll(d * d + 0.5);  // Round to nearest integer

  auto dist = [](pair<ll, ll> p1, pair<ll, ll> p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) +
           (p1.second - p2.second) * (p1.second - p2.second);
  };

  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  reverse(grid.begin(), grid.end());

  vector<vector<pair<ll, ll>>> holds(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'X') {
        holds[i].emplace_back(j, i);
      }
    }
  }

  // Check if starting level has holds
  if (holds[0].empty()) {
    cout << "0\n";
    return;
  }

  vector<ll> prev(holds[0].size(), 1);
  for (int level = 1; level < n; ++level) {
    if (holds[level].empty()) {
      cout << "0\n";
      return;
    }
    vector<ll> dp1(holds[level].size(), 0);
    vector<ll> dp2(holds[level].size(), 0);
    // First pass: transition from previous level
    int l = 0, r = 0;
    ll total = 0;
    for (int i = 0; i < holds[level].size(); ++i) {
      auto& h = holds[level][i];
      // Expand r to include holds with dist <= d_squared
      while (r < prev.size() && dist(holds[level - 1][r], h) <= d_squared) {
        total = (total + prev[r]) % MOD;
        r++;
      }
      // Shrink l to exclude holds with dist > d_squared
      while (l < r && dist(holds[level - 1][l], h) > d_squared) {
        total = (total - prev[l] + MOD) % MOD;
        l++;
      }
      dp1[i] = total;
    }
    // Second pass: same-level transitions (pairs)
    l = 0, r = 0;
    total = 0;
    for (int i = 0; i < holds[level].size(); ++i) {
      auto& h = holds[level][i];
      // Expand r to include holds with dist <= d_squared
      while (r < holds[level].size() && dist(holds[level][r], h) <= d_squared) {
        total = (total + dp1[r]) % MOD;
        r++;
      }
      // Shrink l to exclude holds with dist > d_squared
      while (l < r && dist(holds[level][l], h) > d_squared) {
        total = (total - dp1[l] + MOD) % MOD;
        l++;
      }
      // Subtract dp1[i] to avoid self-pairing
      dp2[i] = (total - dp1[i] + MOD) % MOD;
    }
    // Combine dp1 and dp2
    for (int i = 0; i < holds[level].size(); ++i) {
      dp1[i] = (dp1[i] + dp2[i]) % MOD;
    }
    prev = dp1;
  }

  ll ans = accumulate(prev.begin(), prev.end(), 0LL) % MOD;
  cout << ans << "\n";
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
// }}}
