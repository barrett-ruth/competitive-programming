#include <bits/stdc++.h> // {{{

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

using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
using f128 = long double;

#if __cplusplus >= 202002L
template <typename T> constexpr T MIN = std::numeric_limits<T>::min();

template <typename T> constexpr T MAX = std::numeric_limits<T>::max();

template <typename T> [[nodiscard]] static T sc(auto &&x) {
  return static_cast<T>(x);
}

template <typename T> [[nodiscard]] static T sz(auto &&x) {
  return static_cast<T>(x.size());
}
#endif

static void NO() { std::cout << "NO\n"; }

static void YES() { std::cout << "YES\n"; }

template <typename T> using vec = std::vector<T>;

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
  cin >> n;

  vec<vec<u32>> a(n);
  u32 maxlen = 0;
  for (u32 i = 0; i < n; ++i) {
    cin >> k;
    a[i].resize(k);
    for (u32 j = 0; j < k; ++j) {
      cin >> a[i][j];
    }
    maxlen = max(maxlen, k);
  }

  sort(all(a),
       [](auto const &A, auto const &B) { return A.size() < B.size(); });

  u32 index = 0;
  for (u32 i = 0; i < maxlen;) {
    while (i >= a[index].size()) {
      ++index;
    }

    u32 best = index;
    for (u32 j = index + 1; j < n; ++j) {
      if (lexicographical_compare(a[j].begin() + i, a[j].end(),
                                  a[best].begin() + i, a[best].end())) {
        best = j;
      }
    }

    for (u32 j = i; j < a[best].size(); ++j) {
      cout << a[best][j] << ' ';
    }

    i = a[best].size();
  }

  cout << '\n';
}

int main() { // {{{
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
