// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include "commoncppproblem111.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        // 迭代法
        // queue<TreeNode*> que{};
        // int depth = 0;

        // if (root != nullptr)
        // {
        //     que.push(root);
        // }

        // while (!que.empty())
        // {
        //     depth++;
        //     int size = que.size();

        //     for (size_t i = 0; i < size; i++)
        //     {
        //         TreeNode* node = que.front();
        //         que.pop();

        //         if (node->left == nullptr && node->right == nullptr)
        //         {
        //             return depth;
        //         }

        //         if (node->left != nullptr)
        //         {
        //             que.push(node->left);
        //         }
                
        //         if (node->right != nullptr)
        //         {
        //             que.push(node->right);
        //         }
        //     }
        // }

        // return depth;
        int depth = getDepth(root);
        return depth;
    }

    // 递归法
    int getDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int left_depth = getDepth(root->left);
        int right_depth = getDepth(root->right);

        if (root->left == nullptr && root->right != nullptr)
        {
            return 1 + right_depth;
        }

        if (root->right == nullptr && root->left != nullptr)
        {
            return 1 + left_depth;
        }
        
        return 1 + min(left_depth, right_depth);
    }
};
// @lc code=end

