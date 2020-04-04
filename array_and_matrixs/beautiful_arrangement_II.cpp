// 667 beatiful arrangement II 
// Given two integers n and k, you need to construct a list which contains n different positive integers ranging from 1 to n and obeys the following requirement:
// Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

// If there are multiple answers, print any of them.

// Example 1:
// Input: n = 3, k = 1
// Output: [1, 2, 3]
// Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
// Example 2:
// Input: n = 3, k = 2
// Output: [1, 3, 2]
// Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
// Note:
// The n and k are in the range 1 <= k < n <= 104.

#include<vector>
using namespace std;
// 拆成两部分，第一部分只有一个差，就是1；
// 第二部分，为了构造k-1个不等于1的差，需要k+1个数，所以第一部分的范围就是到n-k-1;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ba;
        int firstPart = n-k-1;
        for(int i=1; i <= firstPart; i++){
            ba.push_back(i);
        }
        
        int start = n-k;
        int last = n;
        while(start <= last){
            ba.push_back(start++);
            if(start <= last){                
                ba.push_back(last--);
            }  
        }
        return ba;
    }
};