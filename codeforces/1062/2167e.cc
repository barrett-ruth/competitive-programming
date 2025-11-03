#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
using i64 = long long;

struct Seg {
  i64 L, R, PL, PR;
  int type;   // 0=interior, 1=left-edge, 2=right-edge
  i64 pos, key;
};

static void eval(Seg& s) {
  if (s.type == 1) {
    s.pos = s.L;
    s.key = s.PL - s.pos;
  } else if (s.type == 2) {
    s.pos = s.R;
    s.key = s.pos - s.PR;
  } else {
    i64 m = (s.PL + s.PR) / 2;
    if (m < s.L) m = s.L;
    if (m > s.R) m = s.R;
    s.pos = m;
    s.key = min(s.pos - s.PL, s.PR - s.pos);
  }
  if (s.key < 0) s.key = 0;
}

struct Cmp {
  bool operator()(const Seg& a, const Seg& b) const { return a.key < b.key; }
};

void solve() {
  int n; i64 k, X;
  cin >> n >> k >> X;
  vector<i64> A(n);
  for (auto& e : A) cin >> e;
  sort(A.begin(), A.end());

  priority_queue<Seg, vector<Seg>, Cmp> pq;

  if (A[0] > 0) {
    Seg s{0, A[0] - 1, A[0], 0, 1, 0, 0};
    eval(s); pq.push(s);
  }
  for (int i = 0; i + 1 < n; ++i) {
    if (A[i] + 1 <= A[i + 1] - 1) {
      Seg s{A[i] + 1, A[i + 1] - 1, A[i], A[i + 1], 0, 0, 0};
      eval(s); pq.push(s);
    }
  }
  if (A.back() < X) {
    Seg s{A.back() + 1, X, 0, A.back(), 2, 0, 0};
    eval(s); pq.push(s);
  }

  i64 printed = 0;
  while (printed < k && !pq.empty()) {
    Seg s = pq.top(); pq.pop();
    cout << s.pos << (printed + 1 == k ? '\n' : ' ');
    ++printed;
    if (s.L <= s.pos - 1) {
      Seg Ls{s.L, s.pos - 1, s.PL, s.PR, s.type, 0, 0};
      eval(Ls); pq.push(Ls);
    }
    if (s.pos + 1 <= s.R) {
      Seg Rs{s.pos + 1, s.R, s.PL, s.PR, s.type, 0, 0};
      eval(Rs); pq.push(Rs);
    }
  }

  i64 last = LLONG_MIN;
  for (int i = 0; printed < k && i < n; ++i) {
    if (A[i] == last) continue;
    last = A[i];
    cout << A[i] << (printed + 1 == k ? '\n' : ' ');
    ++printed;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}


