#include <bits/stdc++.h>

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

template <typename... Args>
void dbg(std::string const &str, Args &&...args) {
  std::cout << std::vformat(str, std::make_format_args(args...));
}

template <typename T>
void dbg(T const &t) {
  std::cout << t;
}

template <std::ranges::range T>
void dbgln(T const &t) {
  if constexpr (std::is_convertible_v<T, char const *>) {
    std::cout << t << '\n';
  } else {
    for (auto const &e : t) {
      std::cout << e << ' ';
    }
    std::cout << '\n';
  }
}

void dbgln() {
  std::cout << '\n';
}

template <typename... Args>
void dbgln(std::string const &str, Args &&...args) {
  dbg(str, std::forward<Args>(args)...);
  cout << '\n';
}

template <typename T>
void dbgln(T const &t) {
  dbg(t);
  cout << '\n';
}

template <typename T>
constexpr T MIN = std::numeric_limits<T>::min();

template <typename T>
constexpr T MAX = std::numeric_limits<T>::max();

template <typename T>
static T sc(auto &&x) {
  return static_cast<T>(x);
}

#define ff first
#define ss second
#define eb emplace_back
#define ll long long
#define ld long double
#define vec vector
#define endl '\n'

#define all(x) (x).begin(), (x).end()
#define rall(x) (r).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())
#define FOR(a, b, c) for (int a = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (int a = (b); (a) > (c); --(a))

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
template <class Key, class Value>
using hashmap = gp_hash_table<
    Key, Value, hashing::custom_hash<Key>, std::equal_to<Key>,
    direct_mask_range_hashing<>, linear_probe_fn<>,
    hash_standard_resize_policy<hash_exponential_size_policy<>,
                                hash_load_check_resize_trigger<>, true>>;
template <class Key>
using hashset = gp_hash_table<
    Key, null_type, hashing::custom_hash<Key>, std::equal_to<Key>,
    direct_mask_range_hashing<>, linear_probe_fn<>,
    hash_standard_resize_policy<hash_exponential_size_policy<>,
                                hash_load_check_resize_trigger<>, true>>;

#endif
#ifdef PB_DS_TREE_POLICY_HPP
template <typename T>
using multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag,
                      tree_order_statistics_node_update>;
template <class Key, class Value = null_type>
using rbtree = tree<Key, Value, std::less<Key>, rb_tree_tag,
                    tree_order_statistics_node_update>;
#endif

struct union_find {
 public:
  union_find(size_t n) : par(n + 1), rank(n + 1, 0) {
    for (size_t u = 0; u < n + 1; ++u)
      par[u] = u;
  };

  void join(int u, int v) {
    u = find(u), v = find(v);

    if (u == v)
      return;

    if (rank[u] < rank[v])
      std::swap(u, v);

    if (rank[u] == rank[v])
      ++rank[u];

    par[v] = u;
  }

  int find(int u) {
    if (u != par[u])
      par[u] = find(par[u]);
    return par[u];
  }

  size_t capacity;
  std::vector<int> par;
  std::vector<int> rank;
};

vec<unordered_set<int>> F, G;

// TODO: union find reset method

void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;

  F.assign(n + 1, unordered_set<int>());
  G.assign(n + 1, unordered_set<int>());

  union_find Fuf(n + 1), Guf(n + 1);

  FOR(i, 0, m1) {
    int u, v;
    cin >> u >> v;
    F[u].insert(v);
    F[v].insert(u);
  }

  FOR(i, 0, m2) {
    int u, v;
    cin >> u >> v;
    G[u].insert(v);
    G[v].insert(u);
    Guf.join(u, v);
  }

  int ans = 0;

  FOR(u, 1, n + 1) {
    auto it = F[u].begin();
    while (it != F[u].end()) {
      int v = *it;
      if (Guf.find(u) != Guf.find(v)) {
        ++ans;
        F[u].erase(it++);
        F[v].erase(u);
      } else {
        ++it;
      }
    }
  }

  FOR(u, 1, n + 1) {
    for (auto v : F[u])
      Fuf.join(u, v);
  }

  FOR(u, 1, n + 1) {
    for (auto v : G[u]) {
      if (Fuf.find(u) != Fuf.find(v)) {
        ++ans;
        Fuf.join(u, v);
      }
    }
  }

  dbgln(ans);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
