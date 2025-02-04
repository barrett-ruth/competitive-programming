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
constexpr T MAX = std::numeric_limits<T>::min();

template <typename T>
static T sc(auto &&x) {
  return static_cast<T>(x);
}

static void NO() {
  std::cout << "NO\n";
}

static void YES() {
  std::cout << "YES\n";
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
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define ROF(a, b, c) for (int(a) = (b); (a) > (c); --(a))

std::random_device rd;
std::mt19937 gen(rd());

void solve() {
  int l = 2, r = 999;

  while (l < r) {
    int x, y;

    if (r - l == 1) {
      dbgln("? {} {}", l, l);
      cout.flush();
      int area;
      cin >> area;
      if (area != (l + 1) * (l + 1)) {
        l = r;
      }
      break;
    } else if (r - l == 2) {
      x = l + 1, y = r - 1;
    } else {
      x = l + (r - l) / 3;
      y = r - (r - l) / 3;
    }

    dbgln("? {} {}", x, y);
    cout.flush();
    int area;
    cin >> area;

    if (area == x * y) {
      l = y + 1;
    } else if (area == x * (y + 1)) {
      l = x + 1;
      r = y;
    } else {
      r = x;
    }
  }

  dbgln("! {}", l);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
