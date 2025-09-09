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

bitset<1000000 + 1> seen;

void solve() {
  seen.reset();

  i32 n, m;
  cin >> n >> m;
  vec<vec<u32>> grid(n, vec<u32>(m));
  for (auto& row : grid)
    for (auto& cell : row)
      cin >> cell;

  queue<pair<i32, i32>> q{{{0, 0}}};
  auto index = [&](i32 r, i32 c) {
    return r * m + c;
  };

  seen.set(index(0, 0));

  auto valid = [&](i32 r, i32 c) {
    return min(r, c) >= 0 && r < n && c < m;
  };

  i32 time = 0;
  i32 ans = MAX<i32>;
  while (!q.empty()) {
    auto qsize{q.size()};

    for (u32 i = 0; i < qsize; ++i) {
      auto [r, c] = q.front();
      q.pop();

      if (c == m - 1) {
        ans = min(ans, time + min(n - 1 - r, (r + 1) % n));
        continue;
      }

      i32 T = time % n;

      if (c < m - 1 && grid[(r + T + 1) % n][c + 1] == 0 &&
          !seen[index(r, c + 1)]) {
        q.emplace(r, c + 1);
        seen.set(index(r, c + 1));
      }

      if (grid[(r + T + 1) % n][c] == 0 && grid[(r + T + 2) % n][c] == 0 &&
          !seen[index((r + 1) % n, c)]) {
        q.emplace((r + 1) % n, c);
        seen.set(index((r + 1) % n, c));
      }
    }

    ++time;
  }

  println("{}", ans == MAX<i32> ? -1 : ans);
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
