// 485 max consecutive ones
// Given a binary array, find the maximum number of consecutive 1s in this array.

// Example 1:
// Input: [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s.
//     The maximum number of consecutive 1s is 3.
// Note:

// The input array will only contain 0 and 1.
// The length of input array is a positive integer and will not exceed 10,000

#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxlength = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count = nums[i] == 0? 0 : ++count;
            maxlength = max(maxlength, count);
        }
        return maxlength;
        // int j = 0;
        // int maxlength = 0;
        // for(int i=0; i < nums.size(); i++){
        //     if(nums[i] != nums[j]){
        //         maxlength = max(maxlength, i-j);
        //         j = i;
        //     }
        // }
        // int last = nums.size()-j;
        // return max(maxlength, last);

    }
};