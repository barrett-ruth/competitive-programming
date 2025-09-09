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
  u32 n, m;
  cin >> n >> m;
  vec<i64> a(n), b(m);
  for (auto& e : a)
    cin >> e;
  for (auto& e : b)
    cin >> e;

  /*
idea: maximize difference from a to b

note: order doesn't matter in matching (but must print output)

sort a?

hm: consider a[0], w/ some remaining candidates

min/max choice from b optimal - take better, alter ptrs

3 6 7 9 10
2 3 5 9 9

8

1 2 4 6
1 2 3 3 5 7

6532


tbh, idk why greedy even works here
     */
  sort(all(a));
  sort(all(b));

  u32 a_l = 0, a_r = n - 1;
  u32 b_l = 0, b_r = m - 1;
  u64 ans = 0;
  while (a_l <= a_r) {
    array<i64, 4> diffs{abs(a[a_l] - b[b_l]), abs(a[a_l] - b[b_r]),
                        abs(a[a_r] - b[b_l]), abs(a[a_r] - b[b_r])};

    auto best_diff = max_element(all(diffs));
    auto i = distance(diffs.begin(), best_diff);

    ans += *best_diff;

    if (i < 2)
      ++a_l;
    else
      --a_r;
    if (i % 2 == 0)
      ++b_l;
    else
      --b_r;
  }
  println("{}", ans);
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
