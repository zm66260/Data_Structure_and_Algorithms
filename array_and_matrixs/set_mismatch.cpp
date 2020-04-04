// 645 set mismatch
// The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

// Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

// Example 1:
// Input: nums = [1,2,2,4]
// Output: [2,3]
// Note:
// The given array size will in the range [2, 10000].
// The given array's numbers won't have any order.

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);
        vector<int> list;
        int dup = -1; int missing = 1;
        for(int i=1; i < nums.size(); i++){
            if(nums[i-1] == nums[i]){dup = nums[i];}
            else if(nums[i-1]+1 != nums[i]){missing = nums[i-1]+1;}
        }
        list = {dup, nums[nums.size()-1] == nums.size()? missing : nums.size()};
        return list;
   }

        void quicksort(vector<int>& nums, int beginindex, int endindex){
            if(endindex <= beginindex) {
                return;
            }
            int pivotidex = partitionsort(nums, beginindex, endindex);
            quicksort(nums, beginindex, pivotidex-1);
            quicksort(nums, pivotidex+1, endindex);
        }

        int partitionsort(vector<int>& nums, int beginIndex, int endIndex){
            int pivotIndex = endIndex;
            int pivotValue = nums[pivotIndex];
            int leftIndex = beginIndex;

            while(leftIndex != pivotIndex){
                if(nums[leftIndex] > pivotValue){
                    nums[pivotIndex] = nums[leftIndex];
                    nums[leftIndex] = nums[pivotIndex -1];
                    nums[pivotIndex-1] = pivotValue;
                    pivotIndex--;
                }
                else{leftIndex++;}
                
            }
            return pivotIndex;
        } 
};