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

vector<string> names;

void solve() {
  u32 n;
  cin >> n;

  vector<pair<string, string>> constraints(n);
  string word, first, last;
  for (u32 i = 0; i < n; ++i) {
    cin >> constraints[i].ff;
    for (u32 j = 0; j < 4; ++j)
      cin >> word;
    cin >> constraints[i].ss;
  }

  vector<string> ans(8, "Z");

  do {
    bool good = true;

    for (auto &[a, b] : constraints) {
      bool ok = false;
      for (i32 j = 0; j < 8; ++j) {
        if (names[j] == a && (j + 1 < 8 && names[j + 1] == b ||
                              j - 1 >= 0 && names[j - 1] == b)) {
          ok = true;
          break;
        }
      }
      if (!ok) {
        good = false;
        break;
      }
    }

    if (good && names < ans) {
      ans = names;
    }

  } while (next_permutation(names.begin(), names.end()));

  for (auto &e : ans)
    cout << e << '\n';
}

int main() { // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  names = {"Bessie", "Buttercup", "Belinda", "Beatrice",
           "Bella",  "Blue",      "Betsy",   "Sue"};
  sort(all(names));

#define PROBLEM_NAME "lineup"

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
