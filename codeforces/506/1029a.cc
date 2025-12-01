#include <bits/stdc++.h>  // {{{

#include <version>
#ifdef __cpp_lib_ranges_enumerate
#include <ranges>
namespace rv = std::views;
namespace rs = std::ranges;
#endif

#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = double;
using f128 = long double;

#if __cplusplus >= 202002L
template <typename T>
constexpr T MIN = std::numeric_limits<T>::min();

template <typename T>
constexpr T MAX = std::numeric_limits<T>::max();
#endif

#ifdef LOCAL
#define db(...) std::print(__VA_ARGS__)
#define dbln(...) std::println(__VA_ARGS__)
#else
#define db(...)
#define dbln(...)
#endif
//  }}}

void solve() {
    u32 n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    vector<int> pi(n, 0);
    for (int i = 1, j = 0; i < n; ++i) {
        while (j && t[i] != t[j]) j = pi[j-1];
        if (t[i] == t[j]) ++j;
        pi[i] = j;
    }
    int ov = pi[n-1];
    print("{}", t);
    for (u32 _ = 1; _ < k; ++_) {
        for (u32 h = ov; h < n; ++h) print("{}", t[h]);
    }
    println();
}

int main() {  // {{{
    std::cin.exceptions(std::cin.failbit);
#ifdef LOCAL
    std::cerr.rdbuf(std::cout.rdbuf());
    std::cout.setf(std::ios::unitbuf);
    std::cerr.setf(std::ios::unitbuf);
#else
    std::cin.tie(nullptr)->sync_with_stdio(false);
#endif
    u32 tc = 1;
    // std::cin >> tc;
    for (u32 t = 0; t < tc; ++t) {
        solve();
    }
    return 0;
}
// }}}
