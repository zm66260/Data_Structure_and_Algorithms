// 337 house robber III
// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Determine the maximum amount of money the thief can rob tonight without alerting the police.

// Example 1:

// Input: [3,2,3,null,3,null,1]

//      3
//     / \
//    2   3
//     \   \ 
//      3   1

// Output: 7 
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:

// Input: [3,4,5,1,3,null,1]

//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1

// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/house-robber-iii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include<map>
#include<vector>
#include<algorithm>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {    
public:
    int rob(TreeNode* root) {
        if(root == nullptr){return 0;}
        if(memo.count(root)){return memo[root];}

        int val1 = root->val;
        if(root->left != nullptr){val1 += rob(root->left->left) + rob(root->left->right);}
        if(root->right != nullptr){val1 += rob(root->right->left) + rob(root->right->right);}
        int val2 = rob(root->left) + rob(root->right);
        root->val = max(val1, val2);

        memo[root] = root->val;
        return root->val;
    }

private:
    map<TreeNode*, int> memo;

};