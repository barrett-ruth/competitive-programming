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
  u64 n;
  i64 f, b, a;
  cin >> n >> f >> a >> b;

  vec<i64> m(n);
  for (auto& e : m) {
    cin >> e;
  }

  i64 prev = 0;
  for (u32 i = 0; i < n; ++i) {
    auto delta = m[i] - prev;
    f -= min(b, delta * a);
    prev = m[i];
  }

  if (f <= 0) {
    NO();
  } else {
    YES();
  }

  /*
     f charge
     off costs b
     on costs 1

     if

     when to turn on/off the phone?

NOTE: phone starts on
     assume phone turns off, then, of course, you have to turn on at m[0]

     so, WLOG, the phone is on

     when to turn off?
     if i have to wait > b to turn off, it will cost me > b; otherwise, it costs
me b

     wait, or turn off then on?
     say delta seconds pass: min(delta * a, 2*b)

details: message sending

iter thru m, take time delta
     */
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
