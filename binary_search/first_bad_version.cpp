// 278 first bad version
// You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

// Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

// You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

// Example:

// Given n = 5, and version = 4 is the first bad version.

// call isBadVersion(3) -> false
// call isBadVersion(5) -> true
// call isBadVersion(4) -> true

// Then 4 is the first bad version.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/first-bad-version
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 寻找具有重复数的左边界

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int h = n;
        while(l < h){
            int mid = l + (h - l) / 2;
            if(!isBadVersion(mid)){
                l = mid + 1;
            }
            else{
                h = mid;
            }
        }
        return h;
        
    }
};