// 257 binary tree paths
// Given a binary tree, return all root-to-leaf paths.

// Note: A leaf is a node with no children.

// Example:

// Input:

//    1
//  /   \
// 2     3
//  \
//   5

// Output: ["1->2->5", "1->3"]

// Explanation: All root-to-leaf paths are: 1->2->5, 1->3

#include<string>
#include<vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

 class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr){return {};}
        dfs(root, "");
        return pathSet;
    }

    void dfs(TreeNode* node, string path){
        if(node == nullptr){
            pathSet.push_back(path.substr(0, path.size()-2));            
            return;
        }

        if(node->left && node->right){
            dfs(node->left, path+to_string(node->val)+"->");
            dfs(node->right, path+to_string(node->val)+"->");
        }
        else if(node->left && !node->right){
            dfs(node->left, path+to_string(node->val)+"->");
        }
        else if(node->right && !node->left){
            dfs(node->right, path+to_string(node->val)+"->");
        }
        else{
            dfs(node->left, path+to_string(node->val)+"->");
        }
    }

private:
    vector<string> pathSet;
};