// 376 wiggle subseuence
// A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

// For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

// Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

// Example 1:

// Input: [1,7,4,9,2,5]
// Output: 6
// Explanation: The entire sequence is a wiggle sequence.
// Example 2:

// Input: [1,17,5,10,13,15,10,5,16,8]
// Output: 7
// Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
// Example 3:

// Input: [1,2,3,4,5,6,7,8,9]
// Output: 2
// Follow up:
// Can you do it in O(n) time?

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/wiggle-subsequence
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


#include<vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2){return nums.size();}
        int count = 1;
        int difference = -(nums[1] - nums[0]);
        int j = 0;
        for(int i = 1; i < nums.size(); i++){
            if(difference * (nums[i] - nums[j]) <= 0){                 
                if(nums[i] - nums[j] != 0){
                    difference = nums[i] - nums[j] > 0 ? 1 : -1;
                    count++;
                }                               
            }
            j = i; 
        }
        return count;

    }
};