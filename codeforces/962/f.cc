#include <bits/stdc++.h>  // {{{

#include <version>
#ifdef __cpp_lib_ranges_enumerate
#include <ranges>
namespace rv = std::views;
namespace rs = std::ranges;
#endif

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
  i64 n, k;
  cin >> n >> k;
  vector<i64> a(n), b(n);
  for (auto& e : a)
    cin >> e;
  for (auto& e : b)
    cin >> e;

  i64 l = 0, r = *max_element(a.begin(), a.end());
  vector<i64> last_a(n);
  i64 ans = 0, operations = 0;

  while (l <= r) {
    i64 m = l + (r - l) / 2, s = 0, o = 0;

    for (u32 i = 0; i < n; ++i) {
      if (a[i] >= m) {
        i64 O = (a[i] - m) / b[i] + 1;
        s += O * a[i] - b[i] * O * (O - 1) / 2;
        o += O;
      }
    }

    if (o <= k) {
      ans = s;
      operations = o;
      for (u32 i = 0; i < n; ++i) {
        i64 O = (a[i] - m) / b[i] + 1;
        if (a[i] >= m) {
          last_a[i] = a[i] - O * b[i];
        }
      }
      r = m - 1;
    } else
      l = m + 1;
  }

  auto brute_force = [&]() {
    set<pair<i64, i64>> tree;
    i64 ans = 0;
    for (i64 i = 0; i < n; ++i)
      if (last_a[i] > 0)
        tree.emplace(last_a[i], i);
    for (i64 _ = 0; _ < k && !tree.empty(); ++_) {
      auto it = prev(tree.end());
      auto [score, i] = *it;
      tree.erase(it);
      ans += score;
      if (score > b[i])
        tree.emplace(score - b[i], i);
    }
    return ans;
  };

  k -= operations;
  if (k > 0)
    ans += brute_force();
  cout << ans << '\n';
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
