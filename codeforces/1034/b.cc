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
  u32 n, j, k;
  cin >> n >> j >> k;

  vec<u32> a(n);
  for (auto& e : a)
    cin >> e;

  u32 strength = a[j - 1];
  u32 same = 0, less = 0, greater = 0;

  // sorting unecessary
  // sort(all(a));

  for (u32 i = 0; i < n; ++i) {
    if (a[i] < strength) {
      ++less;
    }

    if (a[i] == strength) {
      ++same;
    }

    if (a[i] > strength) {
      ++greater;
    }
  }

  u32 eliminated = less;
  if (same > 0)
    eliminated += same - 1;
  if (greater > 0)
    eliminated += greater - 1;

  if (eliminated >= n - k) {
    YES();
  } else {
    NO();
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
