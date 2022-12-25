#include <string>
using std::string;

/**
 * https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/description/
*/
class Solution {
 public:
  string reverseLeftWords(string s, int n) {
    string result = s;
    for (int i = 0; i < s.length(); i++) {
      if (i < n) {
        result[s.length() - n + i] = s[i];
      } else {
        result[i - n] = s[i];
      }
    }

    return result;
  }
};