// 343 integer break
// Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

// Example 1:

// Input: 2
// Output: 1
// Explanation: 2 = 1 + 1, 1 × 1 = 1.
// Example 2:

// Input: 10
// Output: 36
// Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
// Note: You may assume that n is not less than 2 and not larger than 58.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/integer-break
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i-1; j++){
                dp[i] = max(dp[i], max(dp[i-j] * j, (i-j) * j));
            }
        }
        return dp[n];

    }
};