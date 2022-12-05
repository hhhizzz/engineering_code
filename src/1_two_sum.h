#include <unordered_map>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    auto m = std::unordered_map<int, int>();

    for (int i = 0; i < nums.size(); i++) {
      m[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++) {
      auto distance = target - nums[i];
      auto it = m.find(distance);
      if (it != m.end() && it->second != i) {
        return {i, it->second};
      }
    }
    return {};
  }
};