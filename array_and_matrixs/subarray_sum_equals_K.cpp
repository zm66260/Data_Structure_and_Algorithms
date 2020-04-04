// 560 subarray sum equals K
// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

// Example 1:
// Input:nums = [1,1,1], k = 2
// Output: 2
// Note:
// The length of the array is in range [1, 20,000].
// The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/subarray-sum-equals-k
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> presum(nums.size()+1, 0);
        for(int i = 1; i < nums.size()+1; i++){
            presum[i] = presum[i-1] + nums[i-1];
        }

        int count = 0;
        for(int i = 1; i < nums.size()+1; i++){
            for(int j = 0; j < i; j++){
                if(presum[i] - presum[j] == k){
                    count++;
                }
            }
        }
        return count;

    }
};