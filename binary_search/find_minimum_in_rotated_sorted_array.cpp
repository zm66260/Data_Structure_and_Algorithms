// 153 find minimum in rotated sorted array
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

// Find the minimum element.

// You may assume no duplicate exists in the array.

// Example 1:

// Input: [3,4,5,1,2] 
// Output: 1
// Example 2:

// Input: [4,5,6,7,0,1,2]
// Output: 0

#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        while( l < h ){
            int m = l + (h-l) / 2;
            if(nums[m] > nums[h]){
                l = m + 1;
            }
            else{
                h = m;
            }
        }
        return nums[l];

    }
};