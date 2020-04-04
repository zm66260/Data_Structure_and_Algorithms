// 77 combinations
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// Example:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> permute;
        dfs(permute, 1, n, k);
        return permuteSet;
    }

    void dfs(vector<int>& permute, int start, int n,  int k){
        if(k == 0){
            permuteSet.push_back(permute);
            return;
        }
        for(int i = start; i <= n; i++){
            permute.push_back(i);
            dfs(permute, i+1, n, k-1);
            permute.pop_back();
        }
    }

private:
    vector<vector<int>> permuteSet;
};