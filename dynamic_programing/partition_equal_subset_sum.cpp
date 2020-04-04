// 416 partition equal subset sum
// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

// Note:

// Each of the array element will not exceed 100.
// The array size will not exceed 200.
//  

// Example 1:

// Input: [1, 5, 11, 5]

// Output: true

// Explanation: The array can be partitioned as [1, 5, 5] and [11].
//  

// Example 2:

// Input: [1, 2, 3, 5]

// Output: false

// Explanation: The array cannot be partitioned into equal sum subsets.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/partition-equal-subset-sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2){return false;}
        int target = sum / 2;
        vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, 0));
        for(int i = 1; i < nums.size()+1; i++){
            for(int t = 1; t < target+1; t++){
                if(t - nums[i-1] < 0){
                    dp[i][t] = dp[i-1][t];
                }
                else{
                    dp[i][t] = max(dp[i-1][t-nums[i-1]] + nums[i-1], dp[i-1][t]);
                }
            }
        }
        return dp[nums.size()][target] == target;
    }
};