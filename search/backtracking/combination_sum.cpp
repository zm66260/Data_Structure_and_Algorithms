// 39 combination sum
// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// The same repeated number may be chosen from candidates unlimited number of times.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
// Example 2:

// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

// 组合剪枝，避免出现重复的组合  i = start

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        dfs(candidates, path, 0, target);
        return pathSet;
    }

    void dfs(vector<int>&candidates, vector<int>& path, int start, int target){
        if(target <= 0){
            if(target == 0)
                {pathSet.push_back(path);}
            return;
        }

        for(int i = start; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            dfs(candidates, path, i, target - candidates[i]);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> pathSet;
};