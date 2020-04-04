// 524 longest word in dictionary through deleting
// Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

// Example 1:
// Input:
// s = "abpcplea", d = ["ale","apple","monkey","plea"]

// Output: 
// "apple"
// Example 2:
// Input:
// s = "abpcplea", d = ["a","b","c"]

// Output: 
// "a"
// Note:
// All the strings in the input will only contain lower-case letters.
// The size of the dictionary won't exceed 1,000.
// The length of all the strings in the input won't exceed 1,000.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string output = "";
        for(int i = 0; i < d.size(); i++){
            if(d[i].size() < output.size() || (d[i].size() == output.size() && output.compare(d[i]) < 0)){
                continue;
            }
            if(isSubstring(s, d[i])){
                output = d[i];
            }
        }
        return output;

    }

    bool isSubstring(string s1, string s2){
        int p = 0;
        int q = 0;
        while(p < s1.size() && q < s2.size()){
            if(s1[p] == s2[q]){
                q++;
            }
            p++;
        }
        return q == s2.size();
    }
};