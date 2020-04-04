// 345 revere vowels of a string
// Write a function that takes a string as input and reverse only the vowels of a string.

// Example 1:

// Input: "hello"
// Output: "holle"
// Example 2:

// Input: "leetcode"
// Output: "leotcede"
// Note:
// The vowels does not include the letter "y".

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/reverse-vowels-of-a-string
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int p = 0;
        int q = s.size() - 1;
        while(p < q){
            // if(isvowels(s[p]) && isvowels(q)){
            //     char temp = s[p];
            //     s[p] = s[q];
            //     s[q] = temp;
            //     ++p;
            //     --q;
            // }
            if(!isvowels(s[p])){
                ++p;
                continue;
            }
            if(!isvowels(s[q])){
                --q;
                continue;
            }
            swap(s[p++], s[q--]);
        }
        return s;
    }

    bool isvowels(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c== 'I' || c == 'O' || c == 'U'){
            return true;
        }
        else{return false;}
        // return find(vowels.begin(), vowels.end(), c) != vowels.end();
    }

// private:
//     vector<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
};