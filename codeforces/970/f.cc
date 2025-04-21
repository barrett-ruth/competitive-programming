#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr i64 MOD = 1e9 + 7;

i64 modinv(i64 a, i64 m) {
  i64 m0 = m, y = 0, x = 1;
  if (m == 1)
    return 0;
  while (a > 1) {
    i64 q = a / m;
    i64 t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0)
    x += m0;
  return x;
}

void solve() {
  int n;
  cin >> n;
  vector<i64> a(n);
  for (auto &x : a)
    cin >> x;

  i64 total_sum = 0, sum_sq = 0;
  for (auto x : a) {
    total_sum = (total_sum + x) % MOD;
    sum_sq = (sum_sq + x * x) % MOD;
  }

  i64 sum_pairs = (total_sum * total_sum % MOD - sum_sq + MOD) % MOD;
  sum_pairs = sum_pairs * modinv(2, MOD) % MOD;

  i64 total_pairs = (i64)n * (n - 1) / 2 % MOD;
  i64 inv_total_pairs = modinv(total_pairs, MOD);
  i64 ans = sum_pairs * inv_total_pairs % MOD;

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
