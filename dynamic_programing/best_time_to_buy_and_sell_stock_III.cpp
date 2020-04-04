// 123 best time to buy and sell stock III
// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most two transactions.

// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

// Example 1:

// Input: [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//              Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// Example 2:

// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//              engaging multiple transactions at the same time. You must sell before buying again.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){return 0;}
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2, 0)));
        for(int i = 0; i < prices.size(); i++){
            for(int k = 0; k <= 2; k++){
                if(i - 1 < 0){
                    dp[0][0][0] = 0;
                    dp[0][0][1] = INT_MIN / 2;
                    dp[0][1][0] = INT_MIN / 2;
                    dp[0][1][1] = -prices[0];
                    dp[0][2][0] = INT_MIN / 2;
                    dp[0][2][1] = INT_MIN / 2;
                    continue;               
                }
                if(k-1 < 0){
                    dp[i][k][1] = INT_MIN / 2;
                    continue;
                }
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
            }
        }     
        return max(0, max(dp[prices.size()-1][1][0], dp[prices.size()-1][2][0]));
    }
};