// 518 coin change 2
// You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

//  

// Example 1:

// Input: amount = 5, coins = [1, 2, 5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
// Example 2:

// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
// Example 3:

// Input: amount = 10, coins = [10] 
// Output: 1

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/coin-change-2
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
using namespace std;

class Solution {
public:
    // int change(int amount, vector<int>& coins) {
    //     return dfs(coins, 0, amount);
    // }

    // int dfs(vector<int>& coins, int start, int amount){
    //     if(amount <= 0){
    //         return amount == 0? 1 : 0;
    //     }
    //     int count = 0;
    //     for(int i = start; i < coins.size(); i++){
    //         count += dfs(coins, i, amount - coins[i]);
    //     }

    //     return count;
        
    // }

    // int change(int amount, vector<int>& coins){
    //     vector<int> dp(amount+1, 0);
    //     dp[0] = 1;
    //     for(int coin : coins){
    //         for(int i = coin; i <= amount; i++){
    //             dp[i] += dp[i-coin];
    //         }
    //     }
    //     return dp[amount];
    // }

    int change(int amount, vector<int>& coins){
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        for(int i = 0; i < coins.size()+1; i++){
            // 总钱数等于0也是一种方案
            dp[i][0] = 1;
        }
        for(int i = 1; i < coins.size() + 1; i++){
            for(int j = 1; j < amount + 1; j++){
                if(j - coins[i - 1] >= 0){
                    // 对同一个coin的不断重复+对过去已有方案的继承
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[coins.size()][amount];
 
    }

};