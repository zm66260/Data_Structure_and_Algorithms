// 241 different ways to add parentheses
// Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

// Example 1:

// Input: "2-1-1"
// Output: [0, 2]
// Explanation: 
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
// Example 2:

// Input: "2*3-4*5"
// Output: [-34, -14, -10, -10, 10]
// Explanation: 
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/different-ways-to-add-parentheses
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        // cout << "input: " << input << endl;
        vector<int> output;
        for(int i = 0; i < input.size(); i++){
            char c = input[i];
            if(c == '+' || c =='-' || c=='*'){
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1, input.size() - i));
                // for(int i = 0; i < left.size(); i++){
                //     cout << "left: " << left[i] << endl;
                // }
                //  for(int i = 0; i < right.size(); i++){
                //     cout << "right: " << right[i] << endl;
                // }               
                for(int l : left){
                    for(int r : right){
                        switch(c){
                        case '+':
                            output.push_back(l + r);
                            break;
                        case '-':
                            // cout << "l: " << l << "r: " << r << endl;
                            output.push_back(l - r);
                            break;
                        case '*':
                            output.push_back(l * r);
                            break;
                        }  
                    }
                }
              
            }
        }
        if(output.size() == 0){
            // cout << "stoi input: " << stoi(input) << endl;
            output.push_back(stoi(input));
        }  
        // for(int i = 0; i < output.size(); i++){
        //     cout << "stoi: " << output[i] << endl;
        // }
        return output;

    }
};