// 34 find first and last position of element in sorted array
// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 有重复的元素，寻找左边界

#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return {-1, -1};
        }

        int l = 0;
        int h = nums.size() - 1;
        while(l < h){
            int mid = l + (h - l) / 2;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                h = mid;
            }
        }
        
        if(nums[l] == target){
            int r;
            for(r = l; r < nums.size(); r++){
                if(nums[r] != nums[l]){
                    break;
                }
            }
            return {l, r-1};
        }
        else{
            return{-1, -1};
        }
    }
};