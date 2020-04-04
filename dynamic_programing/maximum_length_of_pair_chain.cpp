// 646 maximum length of pair chain
// You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

// Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

// Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

// Example 1:
// Input: [[1,2], [2,3], [3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4]
// Note:
// The number of given pairs will be in the range [1, 1000].

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/maximum-length-of-pair-chain
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


#include<vector>
#include<algorithm>
using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() == 1){return 1;}
        sort(pairs.begin(), pairs.end(), compare);
        vector<int> dp(pairs.size(), 1);
        for(int i = 1; i < pairs.size(); i++){
            for(int j = 0; j < i; j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());


    }
};