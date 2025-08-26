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
  /*
     want sum(o[l:r])==sum(e[l:r])

     for every r:
        opref[r] - opref[l] == epref[r] - epref[l]
        opref[r] - epref[r] == opref[l] - epref[l]
        ^ known O(1)           ^ insert in tree
     */
  u32 n;
  cin >> n;

  vec<i64> a(n);
  for (auto& e : a)
    cin >> e;

  if (n == 1) {
    NO();
    return;
  }

  // NOTE: missed initial array
  // NOTE: had a major problem with your ideas
  // "oh just change the sign, my logic is not right"
  // TRUST YOUR LOGIC, BUT NOT THE IMPL - IMPL != IDEA
  set<i64> pref{0};
  i64 acc = 0;

  for (u32 r = 1; r <= n; ++r) {
    if (r & 1) {
      acc += a[r - 1];
    } else {
      acc -= a[r - 1];
    }

    // dbln("r={}, o={} e={}", r, o, e);

    // NOTE: had this backwards, and honestly idk even why
    if (pref.find(acc) != pref.end()) {
      YES();
      return;
    }

    pref.insert(acc);
  }

  NO();
}

int main() {  // {{{
  std::cin.exceptions(std::cin.failbit);

#ifdef LOCAL
  std::cerr.rdbuf(std::cout.rdbuf());
  std::cout.setf(std::ios::unitbuf);
  std::cerr.setf(std::ios::unitbuf);
#else
  std::cin.tie(nullptr)->sync_with_stdio(false);
#endif

  u32 tc = 1;
  std::cin >> tc;

  for (u32 t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
