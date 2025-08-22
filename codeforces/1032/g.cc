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

template <typename T>
using vec = std::vector<T>;

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
  string s;
  cin >> s;

  /*

     f(x) -> max # 0/1s in x

     count f(s[l: r]) for all l <= r

     formulate it


     f(s[l:r])

     f(s[0:0]) + f(s[0:1]) + f(s[0:2]) + f(s[0:3]) + f(s[0:4]) + ...
     f(s[1:1]) + f(s[1:2]) + f(s[1:3]) + f(s[1:4]) + ...

     one idea: sum f(s[l:r]) = sum min(prefix[0][l][r], prefix[1][l][r]) +
     |prefix[0][l][r] - prefix[1][l[r]]| = sum + sum

     first term:
      = (i + 1) * (n - i), take min

      min doesn't work, since varies

      must leverage: max(x, y) = (x + y + |x-y|)/2 = sum x + y
      for all i:
          cnts[s[i] == 0] += (i + 1) * (n - i)


      div. by 2 after

      second term: |x-y| in an aggregate way



      ret (first + second) / 2
     */
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  u32 tc = 1;
  cin >> tc;

  for (u32 t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
