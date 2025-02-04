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
#define FOR(a, b, c) for (int a = (b); a < (c); ++a)
#define ROF(a, b, c) for (int a = (b); a > (c); --a)

std::random_device rd;
std::mt19937 gen(rd());

static constexpr int MOD = 1000000007;
static constexpr int MAX_N = 2 * 100000 + 1;

static vec<ll> fac(MAX_N + 1, 1);
bitset<MAX_N> seen;

void solve() {
  int n, k;
  cin >> n >> k;
  vec<int> a(n);
  seen.reset();
  for (auto &e : a) {
    cin >> e;
  }
  sort(all(a));

  ll ans = 0;
  dbgln("----------------------");
  dbgln(a);

  FOR(i, 0, n) {
    if (a[i] == 0 || seen[a[i]])
      continue;
    seen[a[i]] = true;
    // count <=, >=
    int lt = distance(a.begin(), lower_bound(all(a), a[i]));
    int gt = distance(upper_bound(all(a), a[i]), a.end());
    int eq = n - lt - gt - 1;

    if (lt + eq < k / 2)
      continue;
    eq -= max(0, k / 2 - lt);
    if (gt + eq < k / 2)
      continue;
    eq -= max(0, k / 2 - gt);

    dbgln("x={}, lt={}, gt={}, remaining eq={}", a[i], lt, gt, eq);
    ans = (ans + (max(1, lt) * max(1, gt)) % MOD) % MOD;

    // count =
    int left = eq;
    if (lt < k / 2)
      eq -= k / 2 - lt;
    if (gt < k / 2)
      eq -= k / 2 - gt;

    // - max(0, (k / 2 - lt)) - max(0, (k / 2 - gt)) + 1;
    //   dbgln("with element {}, have {} choices", a[i], left);
    //   FOR(i, 1, left) {
    //     ll nci = fac[left] / (fac[i] * fac[left - i]);
    //     dbgln("n={} choose i={}, nci={}", n, i, nci);
    //     ans = (ans + nci) % MOD;
    //   }
    // }

    dbgln(ans);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  fac[0] = 1LL;
  FOR(i, 1, MAX_N + 1) {
    fac[i] = i * fac[i - 1];
  }

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
