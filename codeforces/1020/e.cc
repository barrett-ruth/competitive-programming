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
  u32 n, q;
  cin >> n >> q;
  vec<u32> a(n);
  vec<u32> m(n + 1);
  for (u32 i = 0; i < n; ++i) {
    cin >> a[i];
    m[a[i]] = i;
  }

  while (q--) {
    i64 l, r;
    i64 k;
    cin >> l >> r >> k;
    --l;
    --r;

    u32 index = m[k];

    if (!(l <= index && index <= r)) {
      cout << "-1 ";
    } else {
      u32 L = l, R = r;
      u32 lt_need = 0, gt_need = 0, lt_keep = 0, gt_keep = 0;

      while (L <= R) {
        u32 M = L + (R - L) / 2;

        if (M == index) {
          if (gt_need + k + gt_keep > n || lt_need + lt_keep >= k) {
            cout << "-1 ";
          } else {
            cout << max(lt_need, gt_need) * 2 << ' ';
          }
          break;
        } else if (M < index) {
          if (a[M] > k) {
            ++lt_need;
          } else {
            ++lt_keep;
          }
          L = M + 1;
        } else {
          if (a[M] < k) {
            ++gt_need;
          } else {
            ++gt_keep;
          }
          R = M - 1;
        }
      }
    }
  }
  cout << '\n';
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
