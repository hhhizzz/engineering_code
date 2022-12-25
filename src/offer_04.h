#include <vector>
using std::vector;

/**
 * https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/description/
 */
class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
      return false;
    }
    int i = 0, j = matrix[0].size() - 1;
    
    while (i < matrix.size() && j >= 0) {
      auto current = matrix[i][j];
      if (current == target) {
        return true;
      } else if (current < target) {
        // ↓↓↓↓
        i++;
      } else {  // current > target
        // ←←←←
        j--;
      }
    }
    return false;
  }
};