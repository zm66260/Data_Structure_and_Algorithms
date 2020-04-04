// 198 house robber
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
//              Total amount you can rob = 2 + 9 + 1 = 12.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/house-robber
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // 1
        // if(nums.size() == 0) {return 0;}
        // if(nums.size() == 1) {return nums[0];}
        // if(nums.size() == 2) {return max(nums[0], nums[1]);}
        // vector<int> dp(nums.size(), 0);
        // dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        // for(int i = 2; i < nums.size(); i++){
        //     dp[i] = max(dp[i - 1], nums[i]+dp[i-2]);
        // }
        // return dp[nums.size()-1];

        // 2
        // vector<int> dp(nums.size()+2, 0);
        // for(int i = nums.size()-1; i >= 0; i--){
        //     dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
        // }
        // return dp[0];

        // 3
        int dp_i_1 = 0;
        int dp_i_2 = 0;
        int dp_i = 0;
        for(int i = nums.size()-1; i >= 0; i--){
            dp_i = max(dp_i_1, nums[i]+dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;

        }
        return dp_i;

        // 4
        // vector<int> memo(nums.size(), -1); 
        // return dp(nums, memo, 0); 
    }

    // int dp(vector<int>& nums, vector<int>& memo, int start ){
    //     if(start >= nums.size()) {return 0;}
    //     if(memo[start] != -1){return memo[start];}
    //     int res = max(dp(nums, memo, start+1), nums[start] + dp(nums, memo, start+2));
    //     memo[start] = res;
    //     return res;
    // }
};