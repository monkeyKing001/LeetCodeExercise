#include <numeric> // For std::gcd
#define ll long long

class Solution {
public:
  ll lcm(int a, int b) {
    return ((a * b) / gcd(a, b));
  }
  int maxLength(vector<int>& nums) {
    int n = nums.size();
    int maxLength = 0;
    for (int i = 0; i < n; ++i) {
      ll currGCD = nums[i];
      ll currLCM = nums[i];
      ll currProd = nums[i];
      for (int j = i + 1; j < n; ++j) {
        // Update GCD, LCM, and Product for the current subarray
        currGCD = gcd(currGCD, nums[j]);
        currLCM = lcm(currLCM, nums[j]);
        currProd *= nums[j];
        // Check the product equivalence condition
        if (currProd == currLCM * currGCD) {
          maxLength = max(maxLength, j - i + 1);
        }
        else break;
      }
    }
    return maxLength;
  }
};