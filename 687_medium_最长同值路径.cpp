/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// #define VSCODE

#if defined(VSCODE)
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif // VSCODE

class Solution
{
    int ans = 0;

public:
    int dfs(TreeNode* node){
        if(node == nullptr){
            return 0;
        }

        int left = dfs(node->left);
        int right = dfs(node->right);

        int left1 = 0, right1 = 0;

        if(node->left != nullptr && node->left->val == node->val){
            left1 = left + 1;
        }
        if(node->right != nullptr && node->right->val == node->val){
            right1 = right + 1;
        }
        ans = max(left1 + right1, ans);
        return max(left1, right1);
    }
    int longestUnivaluePath(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};
// @lc code=end
