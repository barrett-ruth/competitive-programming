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

#include <stdexcept>
#include <vector>

template <typename T>
class segment_tree {
 public:
  explicit segment_tree(std::vector<T> const& data)
      : n(data.size()), tree(2 * n, sentinel()), lazy(n, sentinel()) {
    for (size_t i = 0; i < n; ++i)
      tree[i + n] = data[i];
    for (int i = n - 1; i > 0; --i)
      tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
  }

  void update(int l, int r, T const& t) noexcept {
    l += n, r += n + 1;
    push(l);
    push(r - 1);
    for (int L = l, R = r; L < R; L /= 2, R /= 2) {
      if (L & 1)
        apply(L++, t);
      if (R & 1)
        apply(--R, t);
    }
    for (l /= 2; l; l /= 2)
      tree[l] = merge(tree[l * 2], tree[l * 2 + 1]);
    for (r = (r - 1) / 2; r; r /= 2)
      tree[r] = merge(tree[r * 2], tree[r * 2 + 1]);
  }

  [[nodiscard]] T query(int l, int r) noexcept {
    l += n, r += n + 1;
    push(l);
    push(r - 1);
    T left = sentinel(), right = sentinel();
    for (; l < r; l /= 2, r /= 2) {
      if (l & 1)
        left = merge(left, tree[l++]);
      if (r & 1)
        right = merge(tree[--r], right);
    }
    return merge(left, right);
  }

 private:
  int n;
  std::vector<T> tree, lazy;

  [[nodiscard]] T merge(T const& a, T const& b) const {
    return a ^ b;
  }

  [[nodiscard]] inline T do_apply(T const& a, T const& b) const {
    return a & b;
  }

  [[nodiscard]] T sentinel() const {
    return 0;
  }

  void push(int i) {
    for (int h = __builtin_clz(n) - __builtin_clz(i); h > 0; --h) {
      int p = i >> h;
      if (lazy[p] != sentinel()) {
        apply(p * 2, lazy[p]);
        apply(p * 2 + 1, lazy[p]);
        lazy[p] = sentinel();
      }
    }
  }

  void apply(int i, T const& t) {
    tree[i] = do_apply(tree[i], t);
    if (i < n)
      lazy[i] = do_apply(lazy[i], t);
  }
};

void solve() {
  int n;
  cin >> n;
  ve<ll> a(n);  //, prefix(n);
  for (auto& e : a)
    cin >> e;
  string s;
  cin >> s;
  // int zeroes = 0;
  ve<ll> zero(n), one(n);
  for (int i = 0; i < n; ++i) {
    //   prefix[i] = a[i] ^ (i ? prefix[i - 1] : 0);
    if (s[i] == '0') {
      zero[i] = a[i];
      one[i] = 0;
    } else {
      one[i] = a[i];
      zero[i] = 0;
    }
    //     zeroes ^= a[i];
  }
  segment_tree<ll> zeroes(zero), ones(one);
  int q;
  cin >> q;
  int cmd, l, r, g;
  while (q--) {
    cin >> cmd;
    if (cmd == 1) {
      cin >> l >> r;
      --l;
      --r;
      zeroes.update(l, r);
      //     zeroes ^= prefix[r] ^ (l ? prefix[l - 1] : 0);
    } else {
      cin >> g;
      if (g == 1) {
        pr("{} ", (g == 1 ? ones : zeroes).query(0, n - 1));
      }
      //     if (g == 0)
      //       pr("{} ", zeroes);
      //     else
      //       pr("{} ", prefix.back() ^ zeroes);
    }
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
