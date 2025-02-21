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
[[nodiscard]] static T sc(auto &&x) {
  return static_cast<T>(x);
}

template <typename T>
[[nodiscard]] static T sz(auto &&x) {
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

struct hash_pair {
  size_t operator()(const pair<int, int> &p) const {
    return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
  }
};

void solve() {
  ll n;
  cin >> n;

  ll full = n * (n + 1) / 2;
  if (full & 1) {
    cout << "NO\n";
    return;
  }
  ll half = full / 2;

  vec<int> ans1, ans2;
  ll total1 = 0;

  for (int i = n; i >= 1; --i) {
    if (total1 + i <= half) {
      ans1.eb(i);
      total1 += i;
    } else {
      ans2.eb(i);
    }
  }

  cout << ans1.size() << endl;
  for (auto e : ans1)
    cout << e << ' ';
  cout << endl;
  cout << ans2.size() << endl;
  for (auto e : ans2)
    cout << e << ' ';
  cout << endl;

  cout << endl;
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);

  solve();

  return 0;
}
// }}}
