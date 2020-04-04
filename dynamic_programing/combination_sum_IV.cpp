// 377 combination sum IV
// Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

// Example:

// nums = [1, 2, 3]
// target = 4

// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)

// Note that different sequences are counted as different combinations.

// Therefore the output is 7.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/combination-sum-iv
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// 有顺序的背包问题，把背包放在最外层循环，一维dp。


#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <=target; i++){
            for (int num : nums){
                if(i >= num){
                    dp[i] = dp[i] >= INT_MAX - dp[i - num]? INT_MAX: dp[i] + dp[i - num];
                }            
            }
        }
        return dp[target];
    }
};