#include <bits/stdc++.h>  // {{{

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

bitset<2 * 100000 + 1> seen;
void solve() {
  seen.reset();
  u32 n;
  cin >> n;
  vec<u32> a(n);
  for (auto& e : a)
    cin >> e;

  vec<u32> ans;

  u32 prefix_or = 0;

  for (u32 i = 0; i < 31; ++i) {
    u32 current_or = prefix_or;
    i32 index = -1;
    for (u32 j = 0; j < n; ++j) {
      if (seen[j])
        continue;

      if ((prefix_or | a[j]) > current_or) {
        current_or = prefix_or | a[j];
        index = j;
      }
    }

    if (index == -1)
      break;

    ans.push_back(a[index]);
    seen[index] = true;
    prefix_or = current_or;
  }

  for (u32 i = 0; i < n; ++i) {
    if (!seen[i]) {
      ans.push_back(a[i]);
    }
  }

  for (u32 i = 0; i < n; ++i) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  u32 tc = 1;
  cin >> tc;

  for (u32 t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
