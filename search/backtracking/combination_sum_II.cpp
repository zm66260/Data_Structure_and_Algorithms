// 40 combination_sum_II
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]

// 1 数组里有重复元素，要避免因此造成结果里有重复的path
// sort(candidates.begin(), candidates.end()); 

// if(i !=0 && candidates[i] == candidates[i-1] && !hasvisited[i-1]){
//     continue;
// }

// 2 path里不允许同一个element被反复使用（两个值相同的元素没关系）
// hasvisited[i] = true;
// path.push_back(candidates[i]);
// dfs(candidates, path, hasvisited, i, target - candidates[i]);
// path.pop_back();
// hasvisited[i] = false;

// 3 避免[a, b] 和[b, a]的组合（相同元素颠倒顺序）同时出现
// 剪枝
// dfs(candidates, path, hasvisited, i, target - candidates[i]);

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {  
        sort(candidates.begin(), candidates.end()); 
        // candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());  

        vector<int> path;
        vector<bool> hasvisited(candidates.size(), false);          
        dfs(candidates, path, hasvisited, 0, target);
        return pathSet;
    }

    void dfs(vector<int>& candidates, vector<int>& path, vector<bool>& hasvisited, int start, int target){
        if(target <= 0){
            if(target == 0)
                {pathSet.push_back(path);}
            return;
        }

        for(int i = start; i < candidates.size(); i++){
            if(i !=0 && candidates[i] == candidates[i-1] && !hasvisited[i-1]){
                continue;
            }
            if(hasvisited[i]){
                continue;
            }
            hasvisited[i] = true;
            path.push_back(candidates[i]);
            dfs(candidates, path, hasvisited, i, target - candidates[i]);
            path.pop_back();
            hasvisited[i] = false;
        }
    }

private:
    vector<vector<int>> pathSet;

};