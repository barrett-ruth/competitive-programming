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

void solve() {
  u32 n, q;
  cin >> n >> q;
  vec<u64> a(n);
  vec<u64> biggest_step(n + 1, 0), prefix(n + 1, 0);
  for (u32 i = 0; i < n; ++i) {
    cin >> a[i];
    biggest_step[i + 1] = max(biggest_step[i], a[i]);
    prefix[i + 1] = prefix[i] + a[i];
  }
  u64 k;
  for (u32 i = 0; i < q; ++i) {
    cin >> k;

    u32 d =
        distance(biggest_step.begin(), upper_bound(all(biggest_step), k)) - 1;
    cout << prefix[d] << " \n"[i == q - 1];
  }

  // vec<u64> a(n + 1);
  // a[0] = 0;
  // for (u32 i = 1; i <= n; ++i) {
  //   cin >> a[i];
  //   a[i] += a[i - 1];
  // }

  // u64 k;
  // vec<pair<u64, u32>> questions(q);
  // vec<u64> ans(q);
  //
  // for (u32 i = 0; i < q; ++i) {
  //   cin >> questions[i].ff;
  //   questions[i].ss = i;
  // }
  //
  // sort(all(questions));
  //
  // u32 j = 0;
  // for (auto& [k, i] : questions) {
  //   u32 J = j;
  //   while (J <= n && a[J] <= k + (J ? a[J - 1] : 0))
  //     ++J;
  //
  //   if (J > j) {
  //     j = J - 1;
  //   }
  //
  //   ans[i] = a[j];
  // }
  //
  // for (u32 i = 0; i < q; ++i) {
  //   cout << ans[i] << " \n"[i == q - 1];
  // }
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
