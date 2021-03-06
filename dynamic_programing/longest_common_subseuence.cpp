// 1143 longest common subsequence
// Given two strings text1 and text2, return the length of their longest common subsequence.

// A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

//  

// If there is no common subsequence, return 0.

//  

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.
//  

// Constraints:

// 1 <= text1.length <= 1000
// 1 <= text2.length <= 1000
// The input strings consist of lowercase English characters only.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/longest-common-subsequence
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for(int i = text1.size()-1; i >=0; i--){
            for(int j = text2.size()-1; j >=0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = dp[i+1][j+1] + 1;
                }
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];

    }
};