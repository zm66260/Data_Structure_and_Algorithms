// 322 coin change
// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// Example 1:

// Input: coins = [1, 2, 5], amount = 11
// Output: 3 
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/coin-change
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount+1, amount+1);
        // dp[0] = 0;
        // for(int i = 0; i < amount+1; i++){
        //     for(int coin : coins){
        //         if( i - coin < 0){continue;}
        //         dp[i] = min(dp[i], dp[i-coin]+1);
        //     }
        // }
        // return dp[amount] == amount+1? -1 : dp[amount];
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount+1, 0));
        for(int i = 0; i < amount + 1; i++){
            dp[0][i] = amount + 1;
        }
        for(int i = 1; i < coins.size() + 1; i++){
            for(int j = 1; j < amount + 1; j++){
                if(j - coins[i-1] >= 0){
                    dp[i][j] = min(dp[i][j-coins[i-1]]+1, dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[coins.size()][amount] == amount+1? -1 : dp[coins.size()][amount];    

    }
};