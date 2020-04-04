// 42 trapping rain water
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

// Example:

// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/trapping-rain-water
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0){return 0;}
        vector<int> left(height.size(), height[0]);
        vector<int> right(height.size(), height[height.size()-1]);

        for(int i = 1; i < height.size(); i++){
            left[i] = max(height[i], left[i-1]);
        }
        for(int i = height.size()-2; i>= 0; i--){
            right[i] = max(height[i], right[i+1]);
        }

        int water = 0;
        for(int i = 1; i < height.size(); i++){
            water += min(left[i], right[i]) - height[i];
        }
        return water;

    }
};