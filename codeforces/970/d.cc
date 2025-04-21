#include <bits/stdc++.h>  // {{{

// https://codeforces.com/blog/entry/96344

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using d64 = double;
using d128 = long double;
template <typename T>
using vec = std::vector<T>;
template <typename T, size_t N>
using arr = std::array<T, N>;
template <typename T1, typename T2>
using pai = std::pair<T1, T2>;

template <typename T>
constexpr T MIN = std::numeric_limits<T>::min();

template <typename T>
constexpr T MAX = std::numeric_limits<T>::max();

template <typename T>
[[nodiscard]] static T sc(auto&& x) {
  return static_cast<T>(x);
}

template <typename T>
[[nodiscard]] static T sz(auto&& x) {
  return static_cast<T>(x.size());
}

static void NO() {
  std::cout << "NO\n";
}

static void YES() {
  std::cout << "YES\n";
}

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#ifdef LOCAL
#define db(...) std::print(__VA_ARGS__)
#define dbln(...) std::println(__VA_ARGS__)
#else
#define db(...)
#define dbln(...)
#endif
//  }}}

bitset<2 * 100000 + 1> black;

void solve() {
  black.reset();

  u32 n;
  cin >> n;
  vec<u32> a(n);
  for (auto& e : a) {
    cin >> e;
    --e;
  }

  char c;
  for (u32 i = 0; i < n; ++i) {
    cin >> c;
    if (c == '1')
      black[i] = true;
  }

  vec<int> cycle_id(n, -1);
  vec<int> cycle_pos(n, -1);
  vec<bool> visited(n, false);
  vec<int> black_count(n, 0);

  for (u32 start = 0; start < n; ++start) {
    if (visited[start])
      continue;

    u32 slow = start;
    u32 fast = start;

    do {
      slow = a[slow];
      fast = a[a[fast]];
    } while (slow != fast);

    u32 cycle_start = slow;
    int cycle_length = 1;
    slow = a[slow];

    while (slow != cycle_start) {
      cycle_length++;
      slow = a[slow];
    }

    slow = cycle_start;
    int cycle_black = 0;
    for (int i = 0; i < cycle_length; ++i) {
      cycle_id[slow] = start;
      cycle_pos[slow] = i;
      visited[slow] = true;

      if (black[slow])
        cycle_black++;

      slow = a[slow];
    }

    black_count[start] = cycle_black;
  }

  vec<int> answer(n, 0);

  for (u32 i = 0; i < n; ++i) {
    if (cycle_id[i] != -1) {
      answer[i] = black_count[cycle_id[i]];
    } else {
      vec<u32> path;
      u32 curr = i;

      while (cycle_id[curr] == -1) {
        path.push_back(curr);
        curr = a[curr];
      }

      for (u32 node : path) {
        if (black[node])
          answer[i]++;
      }

      answer[i] += black_count[cycle_id[curr]];
    }
  }

  for (u32 i = 0; i < n; ++i) {
    cout << answer[i] << ' ';
  }
  cout << '\n';
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
