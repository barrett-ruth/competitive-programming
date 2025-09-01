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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

void solve() {
  u32 n;
  cin >> n;

  vec<u64> a(n);
  for (auto& e : a)
    cin >> e;

  vec<u32> permutation(n);
  for (auto& e : permutation)
    cin >> e;

  __gnu_pbds::tree<pair<u64, u32>, __gnu_pbds::null_type, less<pair<u64, u32>>,
                   __gnu_pbds::rb_tree_tag,
                   __gnu_pbds::tree_order_statistics_node_update>
      tree;
  for (u32 i = 0; i < n; ++i)
    tree.insert({a[i], i});

  u64 ans = 0, count = 0;
  for (u32 i = 0; i < n; ++i) {
    u32 k = min(i + 1, (u32)tree.size());
    u64 score = (u64)k * tree.find_by_order(tree.size() - k)->first;
    if (score > ans) {
      ans = score;
      count = k;
    }
    u32 j = permutation[i] - 1;
    tree.erase({a[j], j});
  }

  println("{} {}", ans, count);
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
