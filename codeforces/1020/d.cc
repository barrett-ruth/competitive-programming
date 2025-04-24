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
  i64 n, m;
  cin >> n >> m;

  vector<i64> a(n), b(m);
  for (auto& e : a)
    cin >> e;
  for (auto& e : b)
    cin >> e;
  a.emplace_back(MIN<i64>);

  i64 ans = MAX<i32>;

  vec<i64> post(m + 1, -1);
  post[m] = n;

  i64 i = n - 1;
  for (i64 j = m - 1; j >= 0 && i >= 0; --j) {
    while (i >= 0 && a[i] < b[j]) {
      --i;
    }

    if (post[j] == -1)
      post[j] = i;
    --i;
  }

  i64 j = 0;
  i64 matched = 0;
  for (i = 0; i <= n && j < m; ++i) {
    if (post[j + 1] >= i) {
      ans = min(ans, b[j]);
    }

    if (a[i] >= b[j]) {
      if (++matched == m) {
        ans = 0;
        break;
      }
      ++j;
    }
  }

  if (ans == MAX<i32>)
    cout << "-1\n";
  else
    cout << ans << '\n';
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
