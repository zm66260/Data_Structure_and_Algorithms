// 744 find smallest letter greater than target
// Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

// Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

// Examples:
// Input:
// letters = ["c", "f", "j"]
// target = "a"
// Output: "c"

// Input:
// letters = ["c", "f", "j"]
// target = "c"
// Output: "f"

// Input:
// letters = ["c", "f", "j"]
// target = "d"
// Output: "f"

// Input:
// letters = ["c", "f", "j"]
// target = "g"
// Output: "j"

// Input:
// letters = ["c", "f", "j"]
// target = "j"
// Output: "c"

// Input:
// letters = ["c", "f", "j"]
// target = "k"
// Output: "c"
// Note:
// letters has a length in range [2, 10000].
// letters consists of lowercase letters, and contains at least 2 unique letters.
// target is a lowercase letter.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// 在寻找右边界的时候，终止条件可以写l<=h, 因为最终l会因为m+1而大于h
#include<vector>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters[0] > target || letters[letters.size()-1] <= target){
            return letters[0];
            }
        int l = 0;
        int h = letters.size()-1;

        while(l <= h){
            int mid = l + (h - l) / 2;
            if(letters[mid] > target){
                h = mid-1;
            }
            else{
                l = mid + 1;
            }
        }
        return letters[l];

    }
};