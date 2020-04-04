// 680 valid palindrome II
// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

// Example 1:
// Input: "aba"
// Output: True
// Example 2:
// Input: "abca"
// Output: True
// Explanation: You could delete the character 'c'.
// Note:
// The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/valid-palindrome-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<string>
using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
        for(int p = 0, q = s.size()-1; p < q; p++, q--){
            if(s[p] != s[q]){
                return isPalindrom(s, p+1, q) || isPalindrom(s, p, q-1);
            }
        }
        return true;
    }

    bool isPalindrom(string s, int p, int q){
        while(p <= q){
            if(s[p] != s[q]){
                return false;
            }
            p++;
            q--;
        }
        return true;
    }
};