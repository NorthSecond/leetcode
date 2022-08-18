/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
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

class Solution
{
public:
    int deepestLeavesSum(TreeNode *root)
    {
        TreeNode *flag = new TreeNode(0, nullptr, nullptr);
        queue<TreeNode *> qu;
        size_t floor = 0;
        unsigned long long nowans = 0;
        qu.push(flag);
        qu.push(root);
        TreeNode *now;
        do {
            now = qu.front();
            qu.pop();
            if(now->val){
                nowans += now->val;
                if (now->left != nullptr){
                    qu.push(now->left);
                }
                if(now->right != nullptr){
                    qu.push(now->right);
                }
            }else{
                if(!qu.empty()){
                    nowans = 0;
                    qu.push(flag);
                }
            }
        } while (!qu.empty());
        delete flag;
        return nowans;
    }
};
// @lc code=end
