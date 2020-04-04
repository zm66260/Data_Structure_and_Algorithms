// 69 sqrt(x)
// Implement int sqrt(int x).

// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

// Example 1:

// Input: 4
// Output: 2
// Example 2:

// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since 
//              the decimal part is truncated, 2 is returned.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/sqrtx
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 因为向下取整使得l最后会等于h,所以要输出l-1
// 用x/mid 而不是mid*mid，因为后者有可能导致超出MAX_INT

class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int h = x;
        int mid;
        int sqrt;
        while(l <= h){
            mid = l + (h-l) / 2;
            sqrt = x / mid;
            if(sqrt == mid){
                return sqrt;
            }
            if(sqrt < mid){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l-1;
    }
};