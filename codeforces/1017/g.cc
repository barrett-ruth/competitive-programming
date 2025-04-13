#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
using f128 = long double;
//  }}}

void solve() {
  i32 q;
  cin >> q;

  deque<i64> dq;
  i64 S = 0;
  i64 total = 0;
  bool reversed = false;

  while (q--) {
    i32 cmd;
    cin >> cmd;

    if (cmd == 1) {  // left cyclic shift
      if (reversed) {
        S += total - dq.front() * dq.size();
        dq.push_back(dq.front());
        dq.pop_front();
      } else {
        S += total - dq.back() * dq.size();
        dq.push_front(dq.back());
        dq.pop_back();
      }
    } else if (cmd == 2) {  // reverse
      S = ((i64)dq.size() + 1) * total - S;
      reversed ^= 1;
    } else {  // append
      i64 k;
      cin >> k;
      if (reversed) {
        dq.push_front(k);
      } else {
        dq.push_back(k);
      }
      total += k;
      S += k * dq.size();
    }

    cout << S << '\n';
  }
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
