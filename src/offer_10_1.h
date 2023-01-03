class Solution {
 public:
  int fib(int n) {
    int f[2]{0, 1};
    for (int i = 2; i <= n; i++) {
      f[i % 2] = (f[0] + f[1]) % 1000000007;
    }
    return f[n % 2];
  }
};