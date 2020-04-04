// 17 letter combinations of a phone number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


// Example:

// Input: "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:

// Although the above answer is in lexicographical order, your answer could be in any order you want.

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){return {};}
        backtracking("", digits);
        return output;
}
    void backtracking(string combination, string digitString){
        if(digitString.size() == 0){
            output.push_back(combination);
            return;
        }
        char digit = digitString[0];
        string letters = letterMap[digit - '1'];
        for(char c : letters){
            // combination += c;
            string newstring(digitString.begin()+1, digitString.end());
            backtracking(combination+c, newstring);
        }

    }
private:
    vector<string> letterMap{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> output;
};