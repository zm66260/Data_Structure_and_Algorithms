// 279 perfect squares
// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

// Example 1:

// Input: n = 12
// Output: 3 
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/perfect-squares
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
using  namespace std;

class Solution {
public: 
    int numSquares(int n){
        vector<int> dp(n+1, n);
        dp[0] = 0;
        for(int i = 1; i <=n; i++){
            for(int j = 0; j<=i-1; j++){
                if(i - j * j >= 0){
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
                }
            }
        }
        return dp[n];
    }

};