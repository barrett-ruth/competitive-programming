#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

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

using ll = long long;
using ld = long double;
template <typename T>
using vec = std::vector<T>;
template <typename T, size_t N>
using arr = std::array<T, N>;

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
//  }}}

void solve() {
  string line;

  while (getline(cin, line)) {
    istringstream iss(line);
    ll m, n;
    iss >> m >> n;
    ll x;
    vector<ll> tires;
    vector<bool> has(m + 1, false);

    while (n--) {
      iss >> x;
      tires.push_back(x);
      has[x] = true;
    }

    ll ans = 0;
    ll i = 0;

    while (i < tires.size()) {
      while (i < tires.size() && !has[tires[i]]) {
        i++;
      }

      if (i >= tires.size()) {
        break;
      }

      if (i == tires.size() - 1) {
        ++ans;
        break;
      }

      ll best_count = 0;
      ll best_delta = 0;

      for (int advance = i + 1; advance < tires.size(); ++advance) {
        ll count = 0;
        ll delta = tires[advance] - tires[i];
        ll cur = tires[i];
        bool bad = false;

        while (cur <= m - 1) {
          if (has[cur]) {
            ++count;
          } else {
            bad = true;
            break;
          }
          cur += delta;
        }

        if (bad) {
          continue;
        }

        if (count > best_count) {
          best_count = count;
          best_delta = delta;
        }
      }

      if (best_delta == 0) {
        has[tires[i]] = false;
        ++ans;
        continue;
      }

      ll cur = tires[i];
      while (cur <= m - 1) {
        has[cur] = false;
        cur += best_delta;
      }

      ++ans;
    }

    cout << ans << endl;
  }
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
// }}}
