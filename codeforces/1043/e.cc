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
  u32 n, m, q;
  cin >> n >> m >> q;

  vec<u64> a(n), b(m);
  for (auto& e : a)
    cin >> e;
  for (auto& e : b)
    cin >> e;
  sort(rall(a));
  sort(rall(b));

  vec<u32> counts(n + m + 1, 0);
  vec<u64> prefix_a(n + 1, 0), prefix_b(m + 1, 0);
  for (u32 i = 1; i <= n; ++i) {
    prefix_a[i] = prefix_a[i - 1] + a[i - 1];
  }
  for (u32 i = 1; i <= m; ++i) {
    prefix_b[i] = prefix_b[i - 1] + b[i - 1];
  }

  i32 i = 0, j = 0;

  for (u32 index = 1; index <= n + m; ++index) {
    counts[index] = counts[index - 1];
    if (j >= m || a[i] >= b[j]) {
      ++counts[index];
      ++i;
    } else {
      ++j;
    }
  }

  u32 x, y, z;
  for (u32 i = 0; i < q; ++i) {
    cin >> x >> y >> z;
    u32 lo = (z > y) ? (z - y) : 0;
    u32 hi = min(x, z);
    u32 take_a = clamp(counts[z], lo, hi);
    u32 take_b = z - take_a;

    println("{}", prefix_a[take_a] + prefix_b[take_b]);
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
