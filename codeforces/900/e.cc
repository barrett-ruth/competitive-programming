#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

template <typename T>
[[nodiscard]] static T MIN() {
  return std::numeric_limits<T>::min();
}

template <typename T>
[[nodiscard]] static T MAX() {
  return std::numeric_limits<T>::max();
}

template <typename T>
[[nodiscard]] static T sc(auto&& x) {
  return static_cast<T>(x);
}

template <typename T>
[[nodiscard]] static T sz(auto&& x) {
  return static_cast<T>(x.size());
}

#define prln(...) std::println(__VA_ARGS__)
#define pr(...) std::print(__VA_ARGS__)

#ifdef LOCAL
#define dbgln(...) std::println(__VA_ARGS__)
#define dbg(...) std::print(__VA_ARGS__)
#endif

inline static void NO() {
  prln("NO");
}

inline static void YES() {
  prln("YES");
}

using ll = long long;
using ld = long double;
template <typename T>
using ve = std::vector<T>;
template <typename T, size_t N>
using ar = std::array<T, N>;
template <typename T1, typename T2>
using pa = std::pair<T1, T2>;
template <typename... Ts>
using tu = std::tuple<Ts...>;
template <typename... Ts>
using dq = std::deque<Ts...>;
template <typename... Ts>
using qu = std::queue<Ts...>;
template <typename... Ts>
using pq = std::priority_queue<Ts...>;
template <typename... Ts>
using st = std::stack<Ts...>;
auto lb = [](auto... args) {
  return std::lower_bound(args...);
};
auto ub = [](auto... args) {
  return std::upper_bound(args...);
};

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
//  }}}

template <typename T>
struct segment_tree {
 public:
  explicit segment_tree(std::vector<T> const& ts) : n(ts.size()) {
    tree.resize(4 * n);
    build(1, 0, n - 1, ts);
  }

  [[nodiscard]] T const query(int const l, int const r) const {
    if (!(0 <= l && l <= r && r < static_cast<int>(n))) {
      throw std::out_of_range(
          "cannot query segment tree of size " + std::to_string(n) +
          " at range [" + std::to_string(l) + ", " + std::to_string(r) + "]");
    }

    return query(1, 0, n - 1, l, r);
  }

  void update(int i, T const& t) {
    if (!(0 <= i && i < static_cast<int>(n))) {
      throw std::out_of_range("cannot update segment tree of size " +
                              std::to_string(n) + " at index " +
                              std::to_string(i));
    }

    update(1, 0, n - 1, i, t);
  }

  [[nodiscard]] size_t lower_bound(T const& t) const noexcept {
    return lower_bound(1, 0, n - 1, t);
  }

  [[nodiscard]] size_t upper_bound(T const& t) const noexcept {
    return upper_bound(1, 0, n - 1, t);
  }

 private:
  inline T const sentinel() const noexcept {
    return -1LL;
  }

  inline T const merge(T const& x, T const& y) const noexcept {
    return x & y;
  }

  void build(size_t const node, size_t const l, size_t const r,
             std::vector<T> const& ts) noexcept {
    if (l == r) {
      tree[node] = ts[l];
    } else {
      int m = l + (r - l) / 2;
      build(2 * node, l, m, ts);
      build(2 * node + 1, m + 1, r, ts);
      tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
  }

  [[nodiscard]] T query(size_t const node, size_t const lower,
                        size_t const upper, size_t const l,
                        size_t const r) const noexcept {
    if (upper < l || r < lower) {
      return sentinel();
    }

    if (l <= lower && upper <= r) {
      return tree[node];
    }

    size_t m = lower + (upper - lower) / 2;

    return merge(query(2 * node, lower, m, l, r),
                 query(2 * node + 1, m + 1, upper, l, r));
  }

  void update(size_t const node, size_t const l, size_t const r, size_t const i,
              T const& t) noexcept {
    if (l == r) {
      tree[node] = t;
    } else {
      size_t m = l + (r - l) / 2;
      if (i <= m) {
        update(2 * node, l, m, i, t);
      } else {
        update(2 * node + 1, m + 1, r, i, t);
      }
      tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
  }

  [[nodiscard]] size_t lower_bound(size_t const node, size_t const l,
                                   size_t const r, T const& t) const noexcept {
    if (l == r) {
      return tree[node] >= t ? l : n;
    }

    size_t m = l + (r - l) / 2;
    if (tree[2 * node] >= t) {
      size_t res = lower_bound(2 * node, l, m, t);
      if (res < n)
        return res;
    }

    return lower_bound(2 * node + 1, m + 1, r, t);
  }

  [[nodiscard]] size_t upper_bound(size_t const node, size_t const l,
                                   size_t const r, T const& t) const noexcept {
    if (l == r) {
      return tree[node] > t ? l : n;
    }

    size_t m = l + (r - l) / 2;
    if (tree[2 * node] > t) {
      size_t res = upper_bound(2 * node, l, m, t);
      if (res < n)
        return res;
    }

    return upper_bound(2 * node + 1, m + 1, r, t);
  }

  size_t n;
  std::vector<T> tree;
};

void solve() {
  int n;
  cin >> n;
  ve<ll> a(n);
  for (auto& e : a)
    cin >> e;
  segment_tree<ll> st(a);
  int q;
  cin >> q;
  int L;
  ll k;
  while (q--) {
    cin >> L >> k;
    --L;
    int l = L;
    int r = n - 1;

    while (l <= r) {
      int m = l + (r - l) / 2;

      if (st.query(L, m) >= k) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    // NOTE: messed up invalid queries, was confused
    // minor details of algorithms still cofnuse
    if (r < L)
      pr("-1 ");
    else
      pr("{} ", r + 1);

    // NOTE: would like to be able to use builtin lower bound but knowledge not
    // good enough
  }
  prln();
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
// }}}
