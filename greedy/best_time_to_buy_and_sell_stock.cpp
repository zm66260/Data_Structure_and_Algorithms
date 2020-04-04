// 121 best time to buy and sell stock
// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

// Note that you cannot sell a stock before you buy one.

// Example 1:

// Input: [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//              Not 7-1 = 6, as selling price needs to be larger than buying price.
// Example 2:

// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minv = INT_MAX;
        int maxv = INT_MIN;
        int indexmin = 0;
        int maxprice = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minv){
                minv = prices[i];                
                indexmin = i;
                maxv = minv;
            }
            if(prices[i] > maxv && i > indexmin){
                maxv = prices[i];
                maxprice = max(maxprice, maxv - minv);
            }
        }
        return maxprice;

    }
};