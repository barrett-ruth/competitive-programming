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

struct S{
  void method() {

  }
};

void solve() {
  /*
     a[i] has factors S, |S| < = log2(MAX_A[i] = 1000)

     want to find rightmost j > i s.t. no common factors

     factor -> [a[i] divisible by]

     iter thru factors of a[i]

     if i have log2(a[i]) factors;
     there are 10^6 factors total
     there are 10 factors here

     so, factor each a[i], and manually compute
     */
  u32 n;
  cin >> n;
  vector<u32> a(n);
  for (auto& e : a)
    cin >> e;

  vector<bitset<1001>> coprime(1001);
  for (u32 i = 1; i <= 1000; ++i) {
    for (u32 j = 1; j <= 1000; ++j) {
      coprime[i][j] = gcd(i, j) == 1;
    }
  }

  vector<u32> right(1001, -1);
  for (u32 i = 0; i < n; ++i) {
    right[a[i]] = i;
  }

  u32 ans = 0;
  for (i32 i = 1; i <= 1000; ++i) {
    for (u32 j = 1; j <= 1000; ++j) {
      if (coprime[i][j] && right[i] != -1 && right[j] != -1) {
        ans = max(ans, right[i] + right[j] + 2);
      }
    }
  }

  if (ans == 0)
    cout << -1;
  else
    cout << ans;
  cout << '\n';
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
