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
  const int LIM = 2 * 1e5;
  bitset<LIM + 1> Apos, Aneg, Bpos, Bneg;
  Apos.reset();
  Aneg.reset();
  Bpos.reset();
  Bneg.reset();

  /* ---------- read input & build bitsets ---------- */
  u32 n, m, q;
  cin >> n >> m >> q;

  vector<i64> a(n), b(m);
  i64 A = 0, B = 0;
  for (u32 i = 0; i < n; ++i) {
    cin >> a[i];
    A += a[i];
  }
  for (u32 i = 0; i < m; ++i) {
    cin >> b[i];
    B += b[i];
  }

  auto add_term = [](i64 t, bitset<LIM + 1>& pos, bitset<LIM + 1>& neg) {
    if (t == 0 || abs(t) > LIM)
      return;
    (t > 0 ? pos : neg).set(abs(t));
  };

  for (u32 i = 0; i < n; ++i)
    add_term(A - a[i], Apos, Aneg);
  for (u32 i = 0; i < m; ++i)
    add_term(B - b[i], Bpos, Bneg);

  vec<vec<u32>> div(LIM + 1);
  for (int d = 1; d <= LIM; ++d)
    for (int v = d; v <= LIM; v += d)
      div[v].push_back(d);

  for (u32 _ = 0; _ < q; ++_) {
    int x;
    cin >> x;
    int y = abs(x);
    bool good = false;

    for (int d : div[y]) {
      int e = y / d;

      if (x > 0) {
        if ((Apos[d] && Bpos[e]) || (Apos[e] && Bpos[d]) ||
            (Aneg[d] && Bneg[e]) || (Aneg[e] && Bneg[d])) {
          good = true;
          break;
        }
      } else {
        if ((Apos[d] && Bneg[e]) || (Apos[e] && Bneg[d]) ||
            (Aneg[d] && Bpos[e]) || (Aneg[e] && Bpos[d])) {
          good = true;
          break;
        }
      }
    }

    good ? YES() : NO();
  }
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  u32 tc = 1;
  // cin >> tc;

  for (u32 t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
