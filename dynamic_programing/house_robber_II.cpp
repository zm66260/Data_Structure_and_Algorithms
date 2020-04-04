// 213 house robber II
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//              because they are adjacent houses.
// Example 2:

// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/house-robber-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0){return 0;}
        if(nums.size() == 1){return nums[0];}
        int res = max(robHouse(nums, 0, nums.size()-2), robHouse(nums, 1, nums.size()-1));
        return res;

    }
    int robHouse(vector<int>& nums, int start, int end){
        int pre1 = 0;
        int pre2 = 0;
        int dp_i = 0;
        for(int i = start; i<=end; i++){
            dp_i = max(pre1, nums[i]+pre2);
            pre2 = pre1;
            pre1 = dp_i;            
        }
        return pre1;
    }
};