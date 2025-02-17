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

void solve() {
  int n, k;
  cin >> n >> k;

  int overlaps = k - 1;

  if (n & 1) {
    // need odd # odds in overlaps
    int odd_count = floor(overlaps / 2);

    cout << (odd_count & 1 ? "YES" : "NO");
  } else {
    int odd_count = ceil(overlaps / 2);
    cout << (odd_count & 1 ? "NO" : "YES");
  }

  cout << '\n';
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
