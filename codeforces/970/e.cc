#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using d64 = double;
using d128 = long double;
template <typename T>
using vec = std::vector<T>;
template <typename T, size_t N>
using arr = std::array<T, N>;
template <typename T1, typename T2>
using pai = std::pair<T1, T2>;

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

#ifdef LOCAL
#define db(...) std::print(__VA_ARGS__)
#define dbln(...) std::println(__VA_ARGS__)
#else
#define db(...)
#define dbln(...)
#endif
//  }}}

#include <bits/stdc++.h>
using namespace std;

void solve() {
  u32 n;
  cin >> n;
  string s;
  cin >> s;
  int ans = s.size();

  if (n & 1) {
    vector<int> pref[2] = {vector<int>(26), vector<int>(26)};
    vector<int> suf[2] = {vector<int>(26), vector<int>(26)};

    for (int i = n - 1; i >= 0; i--) {
      suf[i % 2][s[i] - 'a']++;
    }

    for (int i = 0; i < n; i++) {
      suf[i % 2][s[i] - 'a']--;
      int odd = n;

      for (int k = 0; k < 2; k++) {
        int best = 0;
        for (int j = 0; j < 26; j++) {
          best = max(best, suf[1 - k][j] + pref[k][j]);
        }
        odd -= best;
      }

      ans = min(ans, odd);
      pref[i % 2][s[i] - 'a']++;
    }
  } else {
    vector<int> v[2] = {vector<int>(26), vector<int>(26)};
    for (int i = 0; i < n; i++) {
      v[i % 2][s[i] - 'a']++;
    }
    for (int i = 0; i < 2; i++) {
      int best = 0;
      for (int j = 0; j < 26; j++) {
        best = max(best, v[i][j]);
      }
      ans -= best;
    }
  }

  cout << ans << '\n';
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  int tc = 1;
  cin >> tc;

  for (int t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
