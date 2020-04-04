// 216 combination sum III
// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

// Note:

// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/combination-sum-iii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> numbers{1,2,3,4,5,6,7,8,9};
        vector<int> combination;
        vector<bool> hasvisited(n, false);
        dfs(numbers, combination, hasvisited, 0, k, n);
        return combinationSet;
    }

    void dfs(vector<int>& numbers, vector<int>& combination, vector<bool>& hasvisited, int start, int k, int target){
        if(combination.size() == k || target <= 0){
            if(combination.size() == k && target == 0){
                combinationSet.push_back(combination);
                return;
            }
        }
        for(int i = start; i < numbers.size(); i++){
            if(hasvisited[i]){
                continue;
            }
            hasvisited[i] = true;
            combination.push_back(numbers[i]);
            dfs(numbers, combination, hasvisited, i, k, target - numbers[i]);
            hasvisited[i] = false;
            combination.pop_back();
        }
    }

private:
    vector<vector<int>> combinationSet;
};