// 633 sum of square numbers
// Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

// Example 1:

// Input: 5
// Output: True
// Explanation: 1 * 1 + 2 * 2 = 5
//  

// Example 2:

// Input: 3
// Output: False

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/sum-of-square-numbers
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// #include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0;
        int r = sqrt(c);
        while(l <= r){
            if(pow(l, 2) + pow(r, 2) == c){return true;}
            if(pow(l, 2) + pow(r, 2) > c){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }
};