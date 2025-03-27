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

string reverseIntervals(string s, vector<pair<int, int>>& intervals) {
  int n = s.length();
  vector<int> flip(n + 1, 0);

  for (auto& interval : intervals) {
    int start = interval.ff, end = interval.ss;
    if (start >= 0 && end < n && start <= end) {
      flip[start]++;
      flip[end + 1]--;
    }
  }

  int current = 0;
  for (int i = 0; i < n; ++i) {
    current += flip[i];
    if (current % 2 == 1) {
      int j = n - 1 - i;
      if (i < j) {
        swap(s[i], s[j]);
      }
    }
  }

  return s;
}

void solve() {
  int k, n;
  cin >> n >> k;
  string s;
  cin >> s;
  ve<int> L(k), R(k);
  for (auto& e : L)
    cin >> e;
  for (auto& e : R)
    cin >> e;
  int q;
  cin >> q;
  int x;
  ve<pa<int, int>> intervals;
  while (q--) {
    cin >> x;

    int l = 0, r = k - 1;

    while (l <= r) {
      int m = l + (r - l) / 2;
      if (L[m] <= x) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    int i = r;
    int left = min(x, R[i] + L[i] - x), right = max(x, R[i] + L[i] - x);

    prln("{} {}", left - 1, right - 1);
    intervals.eb(left - 1, right - 1);
  }

  string ans = reverseIntervals(s, intervals);
  prln("{}", ans);
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
