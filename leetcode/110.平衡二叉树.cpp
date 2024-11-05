// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem110.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
class Solution {
public:
    int result = 0;
    bool isBalanced(TreeNode* root) {
        // 1、递归法，前序遍历-根-左-右
        if (root == nullptr)
        {
            return true;
        }
    }

    void isBanlanced(TreeNode* root , int depth)
    {
        
        if(root->left == nullptr && root->right == nullptr)
        {
            return;
        }

        
    }
};
// @lc code=end

