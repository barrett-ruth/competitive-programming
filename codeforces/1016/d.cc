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
#else
#define dbgln(...)
#define dbg(...)
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

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
//  }}}

void solve() {
  ll n;
  int q;
  cin >> n >> q;

  while (q--) {
    char cmd;
    cin >> cmd >> cmd;
    if (cmd == '>') {
      ll r, c;
      cin >> r >> c;
      ll result = 1;
      ll N = 1LL << n;

      while (N > 1) {
        ll half = N / 2;
        ll quarter = (N * N) / 4;

        if (r <= half && c <= half) {
        } else if (r > half && c > half) {
          result += quarter;
          r -= half;
          c -= half;
        } else if (r > half && c <= half) {
          result += 2 * quarter;
          r -= half;
        } else {
          result += 3 * quarter;
          c -= half;
        }

        N = half;
      }

      prln("{}", result);
    } else {
      ll d;
      cin >> d;
      ll r = 1, c = 1;
      ll N = 1LL << n;

      while (N > 1) {
        ll half = N / 2;
        ll quarter = (N * N) / 4;
        // didn't translate d right
        // construction: lb/ub error prone + wrong;
        // think longer on impl

        if (d <= quarter) {
        } else if (d <= 2 * quarter) {
          r += half;
          c += half;
          d -= quarter;
        } else if (d <= 3 * quarter) {
          r += half;
          d -= 2 * quarter;
        } else {
          c += half;
          d -= 3 * quarter;
        }

        N = half;
      }

      prln("{} {}", r, c);
    }
  }
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
