// 217 contains duplicate
// Given an array of integers, find if the array contains any duplicates.

// Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

// Example 1:

// Input: [1,2,3,1]
// Output: true
// Example 2:

// Input: [1,2,3,4]
// Output: false
// Example 3:

// Input: [1,1,1,3,3,4,3,2,4,2]
// Output: true

#include<vector>
#include<map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // map<int, int> nmap;
        // for(int i=0; i < nums.size(); i++){
        //     if(nmap.find(nums[i]) != nmap.end()){return true;}
        //     nmap[nums[i]] = i;
        // }
        // return false;

        unordered_set<int> nset(nums.begin(), nums.end());
        return nums.size() > nset.size();
    }
};