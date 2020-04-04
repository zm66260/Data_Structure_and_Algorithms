// 309 best time to buy and sell stock with cooldown
// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
// Example:

// Input: [1,2,3,0,2]
// Output: 3 
// Explanation: transactions = [buy, sell, cooldown, buy, sell]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int df_i_0 = 0;
        int df_pre_0 = 0;
        int df_i_1 = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            int lastday = df_i_0;
            df_i_0 = max(df_i_0, df_i_1 + prices[i]);
            df_i_1 = max(df_i_1, df_pre_0 - prices[i]);
            df_pre_0 = lastday;
        }
        return df_i_0;
    }
};