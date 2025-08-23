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
  u32 n, k;
  cin >> n >> k;

  vec<u64> a(n);
  map<u64, u32> f;
  for (auto& e : a) {
    cin >> e;
    ++f[e];
  }

  vec<u64> candidates;
  for (auto [number, frequency] : f) {
    if (frequency >= k) {
      candidates.push_back(number);
    }
  }

  sort(all(candidates));

  u32 streak = 0;
  u32 l, r, L, R;
  u32 i = 0;
  while (i < candidates.size()) {
    l = i, r = i;
    while (r + 1 < candidates.size() &&
           candidates[r] + 1 == candidates[r + 1]) {
      ++r;
    }

    if (r - l + 1 > streak) {
      streak = r - l + 1;
      L = candidates[l];
      R = candidates[r];
    }

    i = r + 1;
  }

  if (streak == 0) {
    println("-1");
  } else {
    println("{} {}", L, R);
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
