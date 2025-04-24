#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using d64 = double;
using d128 = long double;
template <typename T>
using vec = std::vector<T>;
template <typename T, size_t N>
using arr = std::array<T, N>;
template <typename T1, typename T2>
using pai = std::pair<T1, T2>;

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

static void NO() {
  std::cout << "NO\n";
}

static void YES() {
  std::cout << "YES\n";
}

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#ifdef LOCAL
#define db(...) std::print(__VA_ARGS__)
#define dbln(...) std::println(__VA_ARGS__)
#else
#define db(...)
#define dbln(...)
#endif
//  }}}

void solve() {
  u32 n;
  i64 k;
  cin >> n >> k;

  vec<i64> a(n), b(n);
  for (auto& e : a)
    cin >> e;

  i64 x;
  bool x_found = false;
  u32 neg_count = 0;
  bool bad = false;
  for (u32 i = 0; i < n; ++i) {
    cin >> b[i];
    if (b[i] == -1) {
      ++neg_count;
    } else {
      auto tx = a[i] + b[i];
      if (x_found && tx != x) {
        bad = true;
        continue;
      }
      x_found = true;
      x = tx;
    }
  }

  if (bad) {
    cout << "0\n";
    return;
  }

  if (neg_count == n) {
    cout << *min_element(all(a)) + k - *max_element(all(a)) + 1 << '\n';
  } else {
    for (u32 i = 0; i < n; ++i) {
      if (!(0 <= x - a[i] && x - a[i] <= k)) {
        cout << "0\n";
        return;
      }
    }

    cout << "1\n";
  }
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  int tc = 1;
  cin >> tc;

  for (int t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
