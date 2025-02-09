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

template <typename... Args>
void pr(std::format_string<Args...> fmt, Args&&... args) {
  std::print(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void pr(std::format_string<Args...> fmt) {
  std::print(fmt);
}

template <typename... Args>
void prln(std::format_string<Args...> fmt, Args&&... args) {
  std::println(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
void prln(std::format_string<Args...> fmt) {
  std::println(fmt);
}

using ll = long long;
using ld = long double;
template <typename T>
using vec = std::vector<T>;

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define FORI(a, b, c) for (int a = (b); a < (c); ++a)
#define ROFI(a, b, c) for (int a = (b); a > (c); --a)
#define FORLL(a, b, c) for (ll a = (b); a < (c); ++a)
#define ROFLL(a, b, c) for (ll a = (b); a > (c); --a)  // }}}

void fill(vec<vec<ll>>& matrix, vec<int>& a, int k) {
  int n = matrix.size();
  int m = matrix[0].size();

  vec<vec<int>> extra(n, vec<int>(m));

  FORI(i, 0, n) {
    FORI(j, 0, m) {
      int top = max(0, i - (k - 1));
      int left = max(0, j - (k - 1));
      int bottom = min(n - k, i);
      int right = min(m - k, j);
      extra[i][j] = (bottom - top + 1) * (right - left + 1);
    }
  }

  vec<pair<int, pair<int, int>>> cells;
  FORI(i, 0, n) {
    FORI(j, 0, m) {
      cells.push_back({extra[i][j], {i, j}});
    }
  }

  sort(rall(cells));

  FORI(i, 0, min(n * m, sz<int>(a))) {
    auto [x, y] = cells[i].ss;
    matrix[x][y] = a[i];
  }
}

long long sums(vector<vector<ll>>& matrix, int k) {
  int n = matrix.size(), m = matrix[0].size();

  vec<vec<ll>> prefix(n + 1, vec<ll>(m + 1, 0));
  FORI(i, 1, n + 1) {
    FORI(j, 1, m + 1) {
      prefix[i][j] = matrix[i - 1][j - 1] + prefix[i - 1][j] +
                     prefix[i][j - 1] - prefix[i - 1][j - 1];
    }
  }
  auto get = [&](int r1, int c1, int r2, int c2) -> ll {
    return prefix[r2 + 1][c2 + 1] - prefix[r2 + 1][c1] - prefix[r1][c2 + 1] +
           prefix[r1][c1];
  };
  ll ans = 0;
  FORI(i, 0, n - k + 1) {
    FORI(j, 0, m - k + 1) {
      ans += get(i, j, i + k - 1, j + k - 1);
    }
  }
  return ans;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int w;
  cin >> w;
  vec<int> a(w);
  for (auto& e : a)
    cin >> e;
  sort(rall(a));

  vector<vector<ll>> matrix(n, vector<ll>(m, 0));

  fill(matrix, a, k);

  prln("{}", sums(matrix, k));
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}  //}}}
