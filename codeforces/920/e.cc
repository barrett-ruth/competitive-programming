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
  i64 n, m;
  cin >> n >> m;

  i64 ar, ac, br, bc;
  cin >> ar >> ac >> br >> bc;

  // NOTE: forgot to adjust frontier + 1 (rly think thru!)

  string ans{"Draw"};
  if (ar < br) {
    i64 frontier = (u64)ceill((ar + br) / 2.0);

    // NOTE: key is alice gets extra move
    // TBH, still confused (see mistaken note above) - don't understand
    // didn't think about "optimal" play - i.e. alice leading one way
    // can bob just go the opposite? then, alice ought to lead straight
    // i think if u dig into the logic alice can lead straight in which bob
    // can't do antyhing, but anyway all of this logic circumvented my mind, smh
    // NOTE: this is why - SIMPLIFY
    // simply consider the two player's positions on the frontier row itself -
    // both on the same alice goes first so she gets extra move if frontier
    // distance odd also, optimal strategy principle (explore too)
    i64 aleft = max((i64)1, ac - (frontier - ar));
    i64 aright = min(m, ac + frontier - ar);

    i64 bleft = max((i64)1, bc - (br - frontier));
    i64 bright = min(m, bc + (br - frontier));

    bool alice_aggressor = (br - ar) & 1;

    if (alice_aggressor) {
      if (aleft <= bleft && aright >= bright) {
        ans = "Alice";
      }
    } else {
      if (bleft <= aleft && bright >= aright) {
        ans = "Bob";
      }
    }
  }

  println("{}", ans);
  /*

--A-------
-A-A------
BB--------
B---------
----------
----------
----------
----------
----------
----------

 Alice
Bob
Draw
Draw
Draw
Alice
Draw
Draw
Bob
Alice
Alice
Draw

idea: consider frontier

note: ar >= br -> DRAW
ow, alice below bob, and there is a frontier

alice/bob have frontier pos - enumerate them
find aggressor - they cannot lose

if aggressor can take all passive piece -> win, print aggressor
ow, draw

chess moment :sunglasses:

O(h) -> ok

to flesh out:

derive frontier row
derive a/b cols on row
derive aggressor

note: only care about the coords
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
