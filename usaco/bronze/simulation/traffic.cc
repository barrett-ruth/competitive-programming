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

#if __cplusplus >= 202002L
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
#endif

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

  string type;
  i64 l, r;
  vector<tuple<string, i64, i64>> segments;
  for (u32 i = 0; i < n; ++i) {
    cin >> type >> l >> r;
    segments.emplace_back(type, l, r);
  }

  i64 lb = 0, ub = 1e9;
  for (auto it = segments.rbegin(); it != segments.rend(); ++it) {
    tie(type, l, r) = *it;
    if (type == "none") {
      lb = max(lb, l);
      ub = min(ub, r);
    } else if (type == "off") {
      lb += l;
      ub += r;
    } else if (type == "on") {
      lb = max(lb - r, (i64)0);
      ub = max(ub - l, (i64)0);
    }
  }
  cout << lb << ' ' << ub << '\n';

  lb = 0, ub = 1e9;
  for (auto& segment : segments) {
    // NOTE: how does this work?
    tie(type, l, r) = segment;
    if (type == "none") {
      lb = max(lb, l);
      ub = min(ub, r);
    } else if (type == "off") {
      lb = max(lb - r, (i64)0);
      ub = max(ub - l, (i64)0);
    } else if (type == "on") {
      lb += l;
      ub += r;
    }
  }

  cout << lb << ' ' << ub << '\n';
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

#define PROBLEM_NAME "traffic"

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
