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
[[nodiscard]] static T sc(auto &&x) {
  return static_cast<T>(x);
}

template <typename T>
[[nodiscard]] static T sz(auto &&x) {
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
  u32 n;
  cin >> n;
  vector<u32> a(n), b(n);
  for (auto &e : a)
    cin >> e;
  for (auto &e : b)
    cin >> e;
  struct Op {
    int t, i;
  };
  vector<Op> ops;
  for (u32 i = 0; i < n; i++)
    for (u32 j = 0; j + 1 < n - i; j++)
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        ops.push_back({1, (int)j + 1});
      }
  for (u32 i = 0; i < n; i++)
    for (u32 j = 0; j + 1 < n - i; j++)
      if (b[j] > b[j + 1]) {
        swap(b[j], b[j + 1]);
        ops.push_back({2, (int)j + 1});
      }
  for (u32 i = 0; i < n; ++i) {
    if (a[i] > b[i]) {
      ops.push_back({3, (int)i + 1});
    }
  }

  // NOTE: did not consider/investigate correctness of bubble sort + naive swap

  println("{}", ops.size());
  for (auto &op : ops) {
    println("{} {}", op.t, op.i);
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
