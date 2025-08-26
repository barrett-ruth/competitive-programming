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

i64 inv_merge(vector<i64>& a, vector<i64>& tmp) {
  if (r - l <= 1)
    return 0;
  int m = (l + r) >> 1;
  i64 ans = inv_merge(a, tmp, l, m) + inv_merge(a, tmp, m, r);
  int i = l, j = m, k = l;
  while (i < m || j < r) {
    if (j == r || (i < m && a[i] <= a[j]))
      tmp[k++] = a[i++];
    else {
      tmp[k++] = a[j++];
      ans += (m - i);
    }
  }
  return ans;
}

void solve() {
  // NOTE: erroneosouyl thought was interval overlaps (even that took too long
  // to code) should've stayed at it and continued, but was tired/acted tired
  // consider the problem statemnt & examples more slowly
  // simplifcation: count the inversions
  i32 n;
  cin >> n;
  vector<pair<i64, i64>> p(n);
  for (i32 i = 0; i < n; ++i)
    cin >> p[i].first >> p[i].second;
  sort(all(p));
  vector<i64> b(n), tmp(n);
  for (i32 i = 0; i < n; ++i)
    b[i] = p[i].second;
  println("{}", inv_merge(b, tmp, 0, n));
}

int main() {  // {{{
  std::cin.exceptions(std::cin.failbit);

#ifdef LOCAL
  std::cerr.rdbuf(std::cout.rdbuf());
  std::cout.setf(std::ios::unitbuf);
  std::cerr.setf(std::ios::unitbuf);
#else
  std::cin.tie(nullptr)->sync_with_stdio(false);
#endif

  u32 tc = 1;
  std::cin >> tc;

  for (u32 t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
