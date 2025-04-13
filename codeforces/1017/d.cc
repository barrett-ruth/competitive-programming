#include <iostream>

int main() {
  int x;
  std::cin >> x;

  while (x--) {
    std::string p, s;
    std::cin >> p >> s;

    size_t pi = 0;
    size_t si = 0;
    while (pi < p.size() && si < s.size()) {
      if (p[pi] != s[si]) {
        break;
      }

      auto TO_MATCH = p[pi];

      size_t LEFT_POS_CHANGE = 0;
      size_t RIGHT_POST_CHANGE = 0;
      while (p[pi] == TO_MATCH) {
        ++LEFT_POS_CHANGE;
        if (++pi == p.size())
          break;
      }
      while (s[si] == TO_MATCH) {
        ++RIGHT_POST_CHANGE;
        if (++si == s.size())
          break;
      }
      // clamp delta
      if (RIGHT_POST_CHANGE < LEFT_POS_CHANGE ||
          RIGHT_POST_CHANGE > 2 * LEFT_POS_CHANGE) {
        break;
      }
    }

    std::cout << (pi == p.size() && si == s.size() ? "YES\n" : "NO\n");
  }

  return 0;
}
