#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
#define ll long long

using ld = long double;

auto inclusive_sum = [](unsigned ll l, unsigned ll r) {
  unsigned ll sum_r = r / 2 * (r + 1);
  if (r % 2)
    sum_r += (r + 1) / 2;
  l--;
  unsigned ll sum_l = l / 2 * (l + 1);
  if (l % 2)
    sum_l += (l + 1) / 2;
  return sum_r - sum_l;
};

auto quad = [](ld a, ld b, ld c) {
  return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
};

void solve() {
  unsigned ll n, k;
  cin >> n >> k;

  ll half = inclusive_sum(k, k + n - 1) / 2;

  ld i = quad(0.5, k + 0.5, -half);

  unsigned ll a = max(1LL, static_cast<ll>(ceil(i)));
  unsigned ll b = min(n, a + 1);

  unsigned ll x = inclusive_sum(k, k + a - 1);
  unsigned ll y = inclusive_sum(k + a, k + n - 1);
  unsigned ll diff1 = x < y ? y - x : x - y;

  x = inclusive_sum(k, k + b - 1);
  y = inclusive_sum(k + b, k + n - 1);
  unsigned ll diff2 = x < y ? y - x : x - y;

  cout << min(diff1, diff2) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
