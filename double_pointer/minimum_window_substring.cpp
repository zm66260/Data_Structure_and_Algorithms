// 76 minimum window substring
// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

// Example:

// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:

// If there is no such window in S that covers all characters in T, return the empty string "".
// If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/minimum-window-substring
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<string>
#include<map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> target;
        map<char, int> window;
        for (char c : t){ 
            if(target.count(c)){
                target[c]++;
            }
            else{
                target[c] = 1;
            }            
        }
        for(char c : t){
            window[c] = 0;
        }

        int left = 0;
        int right = 0;
        int match = 0;
        string minlength = "";
        while(right < s.size()){
            if(target.count(s[right])){
                window[s[right]]++; 
                if(window[s[right]] == target[s[right]]){
                    match++;
                }                 
            }          
            right++;

            while(match == target.size()){
                string substring= s.substr(left, right-left);
                if(minlength.size() > substring.size() || minlength.compare("")==0)
                    minlength = substring;
                if(target.count(s[left])){
                    window[s[left]]--;
                    if(window[s[left]] < target[s[left]]){
                        match--;
                    }
                }
                left++;
            }
        }
        return minlength;

    }
};