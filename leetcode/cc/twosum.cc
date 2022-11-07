#include <unordered_map>
#include <vector>

using namespace std;

class twosum {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> um;

    for (int i = 0;; ++i) {
      auto num = nums.at(i);
      auto it = um.find(target - num);

      if (it != um.end()) return vector<int>{i, it->second};

      um[num] = i;
    }
  }
};
