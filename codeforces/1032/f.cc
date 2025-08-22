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

u64 count_subarrays(i64 s, i64 x, vec<i64>& a) {
  u64 ans = 0;
  map<i64, vec<i32>> pref;
  pref[0].push_back(-1);
  i64 acc = 0;
  i32 last_bad = -1;

  for (u32 r = 0; r < a.size(); ++r) {
    acc += a[r];
    if (a[r] > x)
      last_bad = r;

    i64 target = acc - s;
    auto& indices = pref[target];
    auto it = lower_bound(indices.begin(), indices.end(), last_bad);
    ans += (u64)distance(it, indices.end());

    pref[acc].push_back(r);
  }

  return ans;
}

void solve() {
  u32 n;
  i64 s, x;
  cin >> n >> s >> x;
  vec<i64> a(n);
  for (auto& e : a)
    cin >> e;

  auto X = count_subarrays(s, x, a);
  auto Y = count_subarrays(s, x - 1, a);
  println("{}", X - Y);
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
