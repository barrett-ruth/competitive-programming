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

vector<string> cows;

void solve() {
  u32 n;
  cin >> n;

  unordered_map<string, u32> m;
  u32 x;
  string word;
  for (u32 i = 0; i < n; ++i) {
    cin >> word >> x;
    m[word] += x;
  }

  u32 small = 1e9, ssmall = 1e9;
  if (m.size() < cows.size()) {
    small = 0;
  } else
    for (auto &[_, v] : m)
      small = min(small, v);

  string ans = "Tie";
  for (auto it = m.begin(); it != m.end(); ++it) {
    if (it->second > small && it->second < ssmall) {
      ssmall = it->second;
      ans = it->first;
    } else if (it->second == ssmall) {
      ans = "Tie";
    }
  }

  cout << ans;
}

int main() { // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  cows = {"Bessie",    "Elsie",  "Daisy",    "Gertie",
          "Annabelle", "Maggie", "Henrietta"};

#define PROBLEM_NAME "notlast"

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
