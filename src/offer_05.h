#include <iostream>
#include <string>
using std::string;

class Solution {
 public:
  string replaceSpace(string s) {
    string result;
    for (auto c = s.begin(); c != s.end(); c++) {
      if (*c == ' ') {
        result.append("%20");
      } else {
        result.push_back(*c);
      }
    }
    return result;
  }
};