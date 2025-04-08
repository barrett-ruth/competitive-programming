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
[[nodiscard]] static T sc(auto &&x) {
  return static_cast<T>(x);
}

template <typename T>
[[nodiscard]] static T sz(auto &&x) {
  return static_cast<T>(x.size());
}

#define prln(...) std::println(__VA_ARGS__)
#define pr(...) std::print(__VA_ARGS__)

#define dbgln(...) std::println(__VA_ARGS__)
#define dbg(...) std::print(__VA_ARGS__)

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

// https://mirror.codeforces.com/blog/entry/124683

namespace hashing {
using i64 = std::int64_t;
using u64 = std::uint64_t;
static const u64 FIXED_RANDOM =
    std::chrono::steady_clock::now().time_since_epoch().count();

#if USE_AES
std::mt19937 rd(FIXED_RANDOM);
const __m128i KEY1{(i64)rd(), (i64)rd()};
const __m128i KEY2{(i64)rd(), (i64)rd()};
#endif

template <class T, class D = void>
struct custom_hash {};

template <class T>
inline void hash_combine(u64 &seed, T const &v) {
  custom_hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b97f4a7c15 + (seed << 12) + (seed >> 4);
};

template <class T>
struct custom_hash<T,
                   typename std::enable_if<std::is_integral<T>::value>::type> {
  u64 operator()(T _x) const {
    u64 x = _x;
#if USE_AES
    __m128i m{i64(u64(x) * 0xbf58476d1ce4e5b9u64), (i64)FIXED_RANDOM};
    __m128i y = _mm_aesenc_si128(m, KEY1);
    __m128i z = _mm_aesenc_si128(y, KEY2);
    return z[0];
#else
    x += 0x9e3779b97f4a7c15 + FIXED_RANDOM;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
#endif
  }
};

template <class T>
struct custom_hash<T, std::void_t<decltype(std::begin(std::declval<T>()))>> {
  u64 operator()(T const &a) const {
    u64 value = FIXED_RANDOM;
    for (auto &x : a)
      hash_combine(value, x);
    return value;
  }
};

template <class... T>
struct custom_hash<std::tuple<T...>> {
  u64 operator()(const std::tuple<T...> &a) const {
    u64 value = FIXED_RANDOM;
    std::apply(
        [&value](T const &...args) {
          (hash_combine(value, args), ...);
        },
        a);
    return value;
  }
};

template <class T, class U>
struct custom_hash<std::pair<T, U>> {
  u64 operator()(std::pair<T, U> const &a) const {
    u64 value = FIXED_RANDOM;
    hash_combine(value, a.first);
    hash_combine(value, a.second);
    return value;
  }
};
};  // namespace hashing

#ifdef PB_DS_ASSOC_CNTNR_HPP
template <class Key, class Value = null_type>
using hashtable = gp_hash_table<
    Key, Value, hashing::custom_hash<Key>, std::equal_to<Key>,
    direct_mask_range_hashing<>, linear_probe_fn<>,
    hash_standard_resize_policy<hash_exponential_size_policy<>,
                                hash_load_check_resize_trigger<>, true>>;

#endif
#ifdef PB_DS_TREE_POLICY_HPP
template <typename T>
using multitree = tree<T, null_type, std::less_equal<T>, rb_tree_tag,
                       tree_order_statistics_node_update>;
template <class Key, class Value = null_type>
using rbtree = tree<Key, Value, std::less<Key>, rb_tree_tag,
                    tree_order_statistics_node_update>;
#endif

void solve() {
  size_t n;
  cin >> n;
  ve<ve<int>> tree(n + 1);
  hashtable<pa<int, int>, int> edges;
  for (size_t i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    tree[u].eb(v);
    tree[v].eb(u);
    edges[{u, v}] = i + 1;
    edges[{v, u}] = i + 1;
  }

  if (n % 3 != 0) {
    prln("-1");
    return;
  }

  if (n == 3) {
    prln("0\n");
    return;
  }

  /*
     1. gather leaves
     2. build up q; invariant = nodes are unused bot level
     3. test leaves:
        a) ^ pattern; all unused; mark all as used; pop self + neighbor, push
par par
          - the cut is from par to par par; save
        b) / or \; all unused; mark all used; pop self, push par par par
          - the cut is from par par to par par par

NOTE: ignore the last (i..e root) cut in output

NOTE: core assumption that tree must be binary was wrong
problem: didn't even contest this idea
     */

  queue<int> q{{1}};
  ve<pa<int, int>> cuts;
  ve<int> leaves, par(n + 1, -1);
  par[1] = 1;
  // started 10:17
  // TODO: no idea why the seen [] is necessary here
  // NOTE: missed idea of deepest leaves first
  // NOTE: missed idea/complexity of traversal, popping, and the trees first
  // SO: what did i learn?

  auto kids = [&](int u) {
    return tree[u].size() - (u != 1);
  };

  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      auto u = q.front();
      q.pop();
      if (kids(u) == 0)
        leaves.eb(u);
      for (auto v : tree[u]) {
        if (v != par[u]) {
          par[v] = u;
          q.emplace(v);
        }
      }
    }
  }

  reverse(all(leaves));

  bitset<2 * 100000 + 1> seen;
  for (auto leaf : leaves)
    q.emplace(leaf);

  if (leaves.empty()) {
    prln("-1");
    return;
  }

  while (!q.empty()) {
    auto u = q.front();
    q.pop();

    if (seen[u] || seen[par[u]]) {
      continue;
    }

    seen[u] = seen[par[u]] = true;
    if (kids(par[u]) == 2) {
      for (auto v : tree[par[u]]) {
        if (v != u && v != par[par[u]]) {
          seen[v] = true;
          break;
        }
      }
      q.emplace(par[par[u]]);
      if (par[u] != par[par[u]])
        cuts.eb(par[u], par[par[u]]);
    } else {
      if (seen[par[par[u]]]) {
        break;
      }
      seen[par[par[u]]] = true;
      q.emplace(par[par[par[u]]]);
      if (par[par[u]] != par[par[par[u]]])
        cuts.eb(par[par[u]], par[par[par[u]]]);
    }
  }

  if (cuts.empty()) {
    prln("-1");
    return;
  }

  prln("{}", cuts.size());
  for (int i = 0; i < sz<int>(cuts); ++i) {
    pr("{} ", edges[{cuts[i].ff, cuts[i].ss}]);
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
