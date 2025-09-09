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

bitset<100000 + 1> friends;
void solve() {
  /*
     binary search on alpha

     how to know if i can choose at least n - 1 shops to give each guy a present
     basically, choose, out of all m shops, n shops, one gives each guy a
present (in the worst)

     hm - must dynamically, per bsearch query, filter arrays

     consider each array: if someone unset can be set, + 1 to count, update max
     if already set, take max of large value

challenge: n - 1 shops, not  all n
 take a step back:

 we have m arrays, each which set values offriend individually

 consider each friend separately - have multiple values of joy set to; filter to
>= mid alphaq

 not nec. choose ones that set most -> greedy

 ok - one shop per friend - per friend, iterate - find shop that sets their joy
>= alpha

 now, either < n (bad) or n shops - consider each friend as the "substitute"
candidate

 in other words, consider each friend, and iter AGAIN thru the shit - can we
find ANOTHER diff array setting this guy, as well as setting another friend?

 if so, done!
     */

  u32 m, n;
  cin >> m >> n;

  vec<vec<u64>> p(m, vec<u64>(n));
  u64 maxp = 0;
  for (auto& row : p) {
    for (auto& e : row) {
      cin >> e;
      maxp = max(maxp, e);
    }
  }

  u64 l = 1, r = maxp;

  auto ok = [&](u64 alpha) {
    friends.reset();
    bool both_covered = false;

    for (auto& shop : p) {
      u32 shop_count = 0;
      for (u32 i = 0; i < n; ++i) {
        if (shop[i] >= alpha) {
          ++shop_count;
          friends.set(i);
        }
      }
      both_covered |= shop_count > 1;
    }

    return friends.count() == n && both_covered;
  };

  while (l <= r) {
    u64 alpha = l + (r - l) / 2;

    if (ok(alpha)) {
      l = alpha + 1;
    } else {
      r = alpha - 1;
    }
  }

  println("{}", r);
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
