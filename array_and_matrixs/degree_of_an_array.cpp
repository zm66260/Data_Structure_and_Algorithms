// 697 degree of an array
// Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

// Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

// Example 1:
// Input: [1, 2, 2, 3, 1]
// Output: 2
// Explanation: 
// The input array has a degree of 2 because both elements 1 and 2 appear twice.
// Of the subarrays that have the same degree:
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// The shortest length is 2. So return 2.
// Example 2:
// Input: [1,2,2,3,1,4,2]
// Output: 6
// Note:

// nums.length will be between 1 and 50,000.
// nums[i] will be an integer between 0 and 49,999.

#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> counts;
        map<int, int> left;
        map<int, int> right;

        for(int i = 0; i < nums.size(); i++){
            if(!counts.count(nums[i])){
                counts.insert(pair<int, int>(nums[i], 1));
                left.insert(pair<int, int>(nums[i], i));
                right.insert(pair<int, int>(nums[i], i));
            }
            else{
                ++counts[nums[i]];
                right[nums[i]] = i;  
            }
        }

        int mostfre = counts[nums[0]];
        vector<int> condidate;
        for(auto iter = counts.begin(); iter != counts.end(); iter++){
            if(iter->second > mostfre){
                mostfre = iter->second;
                condidate.clear();
                condidate.push_back(iter->first);
            }
            else if(iter->second == mostfre){
                condidate.push_back(iter->first);
            }
        }

        int minlength = nums.size();
        for(int c : condidate){
            minlength = min(minlength, right[c] - left[c] + 1);
        }

        return minlength;
    }
};