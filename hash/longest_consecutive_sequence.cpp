// 128 longest consecutive sequence
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// Your algorithm should run in O(n) complexity.

// Example:

// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numset;
        for (int num : nums){
            numset.insert(num);
        }
        int maxlength = 0;
        for(auto iter = numset.begin(); iter != numset.end(); iter++){
            if(!numset.count(*iter - 1)){
                int currnum = *iter;
                int currlength = 1;

                while(numset.count(currnum + 1)){
                    currnum++;
                    currlength++;
                }
                maxlength = max(maxlength, currlength);
            }
        }
        return maxlength;
    }

    
};