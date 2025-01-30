#include <bits/stdc++.h>

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

template <typename... Args>
void print(std::string const &str, Args &&...args) {
  std::cout << std::vformat(
      str,
      // make_format_args binds arguments to const
      str, std::make_format_args(static_cast<Args const &>(args)...));
}

template <typename T>
void print(T const &t) {
  std::cout << t;
}

template <std::ranges::range T>
void print(T const &t) {
  if constexpr (std::is_convertible_v<T, char const *>) {
    std::cout << t << '\n';
  } else {
    for (auto const &e : t) {
      std::cout << e << ' ';
    }
    std::cout << '\n';
  }
}

template <typename... Args>
void println(std::string const &str, Args &&...args) {
  print(str, std::forward<Args>(args)...);
  cout << '\n';
}

template <typename T>
void println(T const &t) {
  print("{}\n", t);
}

template <std::ranges::range T>
void println(T const &t) {
  cout << t << '\n';
}

void println() {
  std::cout << '\n';
}

template <typename T>
T MAX() {
  return std::numeric_limits<T>::max();
}

template <typename T>
T MIN() {
  return std::numeric_limits<T>::min();
}

#define ff first
#define ss second
#define eb emplace_back
#define ll long long
#define ld long double
#define vec vector

#define all(x) (x).begin(), (x).end()
#define rall(x) (r).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

#ifdef LOCAL
#define dbg(x) cout << __LINE__ << ": " << #x << "=<" << (x) << ">\n";
#else
#define dbg(x)
#endif

static constexpr int MOD = 1e9 + 7;

#define FOR(a, b, c) for (int a = b; a < c; ++a)

void solve() {
  int n, d, k;
  cin >> n >> d >> k;
  vec<int> start(n + 1);
  vec<int> end(n + 1);
  while (k--) {
    int l, r;
    cin >> l >> r;
    ++start[l];
    ++end[r];
  }

  // prefix
  FOR(i, 1, n + 1) {
    start[i] += start[i - 1];
    end[i] += end[i - 1];
  }

  int brother = MIN<int>(), mother = MAX<int>();
  int brother_day = 0, mother_day = 0;
  FOR(i, 0, n - d + 1) {
    if (start[i + d] - end[i] > brother) {
      brother = start[i + d] - end[i];
      brother_day = i;
    }
    if (start[i + d] - end[i] < mother) {
      mother = start[i + d] - end[i];
      mother_day = i;
    }
  }
  cout << (brother_day + 1) << ' ' << (mother_day + 1) << '\n';
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
