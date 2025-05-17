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

unordered_map<u32, u32> factor_counts;
vector<u32> primes;

void solve() {
  u32 n;
  cin >> n;
  vector<u32> a(n);
  for (auto& e : a)
    cin >> e;

  factor_counts.clear();

  // NOTE: factorization skills are weak,. i.e. number theory and prime
  // factorization i.e. skipping over 2
  // also could binary search
  // // NOTE: thought it was "minimum operations" complicating it
  for (auto e : a) {
    for (const auto& p : primes) {
      if (p * p > e)
        break;
      u32 count = 0;
      while (e % p == 0) {
        ++count;
        e /= p;
      }
      if (count > 0) {
        factor_counts[p] += count;
      }
    }
    if (e > 1) {
      ++factor_counts[e];
    }
  }

  for (const auto& [factor, count] : factor_counts) {
    if (count % n) {
      NO();
      return;
    }
  }
  YES();
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  vector<bool> P(10001, true);
  P[0] = P[1] = false;
  for (u32 p = 2; p * p <= 10000; ++p) {
    if (P[p]) {
      for (u32 i = p * p; i <= 10000; i += p) {
        P[i] = false;
      }
    }
  }

  for (u32 i = 2; i <= 10000; ++i) {
    if (P[i]) {
      primes.push_back(i);
    }
  }

  u32 tc = 1;
  cin >> tc;

  for (u32 t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
