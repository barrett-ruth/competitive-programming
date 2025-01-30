#include <bits/stdc++.h>

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

template <typename... Args>
void print(std::string const &str, Args &&...args) {
  std::cout << std::vformat(str,
                            // make_format_args binds arguments to const
                            std::make_format_args(args...));
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
#define FOR(a, b, c) for (int a = b; a < c; ++a)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define randint(a, b) uniform_int_distribution(a, b)(rng)

void YES() {
  cout << "YES\n";
}
void NO() {
  cout << "NO\n";
}

#ifdef LOCAL
#define dbg(x) cout << __LINE__ << ": " << #x << "=<" << (x) << ">\n";
#else
#define dbg(x)
#endif

static constexpr int MOD = 1e9 + 7;

void solve() {
  /*
     n, k; SUM ai = n, same parity

     n odd: k even -> NO; k odd -> YES
     n even: k even: odd #s -> NO, only even
   */
  int n, k;
  cin >> n >> k;

  if (k > n) {
    NO();
    return;
  }

  if ((n - 2 * (k - 1)) % 2 == 0 && (n - 2 * (k - 1)) > 0) {
    YES();
    FOR(i, 1, k)
    cout << 2 << ' ';
    cout << n - 2 * (k - 1) << '\n';
  } else if ((n - k + 1) & 1) {
    YES();
    FOR(i, 1, k)
    cout << 1 << ' ';
    cout << n - k + 1 << '\n';
  } else
    NO();
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
