#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

#define prln(...) std::println(__VA_ARGS__)
#define pr(...) std::print(__VA_ARGS__)

#ifdef LOCAL
#define dbgln(...) std::println(__VA_ARGS__)
#define dbg(...) std::print(__VA_ARGS__)
#else
#define dbgln(...)
#define dbg(...)
#endif
//  }}}

bitset<1441> seen;
void solve() {
  string s;
  int x;
  cin >> s >> x;
  int start = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
  seen.reset();
  int ans = 0;
  auto is_palindrome = [&](string const& S) {
    int l = 0, r = S.size() - 1;

    while (l < r) {
      if (S[l++] != S[r--])
        return false;
    }

    return true;
  };
  auto mutate = [&](int time) {
    int hour = time / 60;
    string hour_part = to_string(hour);
    if (hour_part.size() == 1)
      hour_part = "0" + hour_part;
    int minute = time % 60;
    string minute_part = to_string(minute);
    if (minute_part.size() == 1)
      minute_part = "0" + minute_part;
    return hour_part + ":" + minute_part;
  };
  while (!seen[start]) {
    if (is_palindrome(s))
      ++ans;
    seen[start] = true;
    start = (start + x) % 1440;
    s = mutate(start);
  }
  cout << ans << '\n';
}

int main() {  // {{{
  cin.tie(nullptr)->sync_with_stdio(false);
  cin.exceptions(cin.failbit);

  int tc = 1;
  cin >> tc;

  for (int t = 0; t < tc; ++t) {
    solve();
  }

  return 0;
}
// }}}
