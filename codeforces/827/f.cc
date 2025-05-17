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
  u32 q;
  cin >> q;
  vec<u64> S(26, 0), T(26, 0);
  u64 scount = 1, tcount = 1;
  S[0] = T[0] = 1;
  u64 cmd, k;
  string x;
  for (u64 i = 0; i < q; ++i) {
    cin >> cmd >> k >> x;
    if (cmd == 1) {
      for (auto c : x) {
        S[c - 'a'] += k;
      }
      scount += k * x.size();
    } else {
      for (auto c : x) {
        T[c - 'a'] += k;
      }
      tcount += k * x.size();
    }
    int loS = 0;
    while (loS < 26 && S[loS] == 0)
      ++loS;

    int hiT = 25;
    while (hiT >= 0 && T[hiT] == 0)
      --hiT;

    bool ok;
    if (loS < hiT) {
      ok = true;
    } else if (loS > hiT) {
      ok = false;
    } else {
      int c = loS;

      bool biggerInS = false;
      for (int ch = c + 1; ch < 26 && !biggerInS; ++ch)
        biggerInS = S[ch] > 0;

      if (biggerInS)
        ok = false;
      else
        ok = S[c] < T[c];
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
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
