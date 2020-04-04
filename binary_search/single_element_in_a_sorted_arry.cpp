// 540 single element in a sorted array
// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

//  

// Example 1:

// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: [3,3,7,7,10,11,11]
// Output: 10
//  

// Note: Your solution should run in O(log n) time and O(1) space.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/single-element-in-a-sorted-array
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 终止条件l < h 避免 mid + 1 越界 

#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        while(l < h){
            int mid = l + (h - l) / 2;
            bool isEven = (h - mid) % 2 == 0;
            if(nums[mid] == nums[mid+1]){
                if(isEven){
                    l = mid + 2;
                }
                else{
                    h = mid - 1;
                }
            }
            else if(nums[mid] == nums[mid-1]){
                if(isEven){
                    h = mid - 2;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                return nums[mid];
            }
        }
        return nums[l];

    }
};