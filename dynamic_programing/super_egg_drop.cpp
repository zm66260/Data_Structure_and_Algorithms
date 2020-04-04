// 887 super egg drop
// You are given K eggs, and you have access to a building with N floors from 1 to N. 

// Each egg is identical in function, and if an egg breaks, you cannot drop it again.

// You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.

// Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N). 

// Your goal is to know with certainty what the value of F is.

// What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?

//  

// Example 1:

// Input: K = 1, N = 2
// Output: 2
// Explanation: 
// Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
// Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
// If it didn't break, then we know with certainty F = 2.
// Hence, we needed 2 moves in the worst case to know what F is with certainty.
// Example 2:

// Input: K = 2, N = 6
// Output: 3
// Example 3:

// Input: K = 3, N = 14
// Output: 4

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/super-egg-drop
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> memo(K+1, vector<int>(N+1, -1));
        return dp(memo, K, N);
    }

    int dp(vector<vector<int>>& memo, int K, int N){
        if(K == 1){return N;}
        if(N == 0){return 0;}
        if(memo[K][N] != -1){
            return memo[K][N];
        }
        int res = INT_MAX;
        // for(int i = 1; i < N+1; i++){
        //     res = min(res, max(dp(memo, K-1, i-1), dp(memo, K, N-i)) + 1);                   
        // }
        int l = 1; 
        int h = N;
        while(l <= h){
            int m = l + (h-l) / 2;
            int broken = dp(memo, K-1, m-1);
            int nonbroken = dp(memo, K, N-m);
            if(broken > nonbroken){
                h = m - 1;
                res = min(res, broken + 1);
            }
            else{
                l = m + 1;
                res = min(res, nonbroken + 1);
            }
        }
        memo[K][N] = res; 
        return res;
    }
   
};