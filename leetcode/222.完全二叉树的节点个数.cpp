// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem222.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int num_node{0};

    int countNodes(TreeNode* root) {
        // 完全二叉树：二叉树的高度为h，如果1~h层的节点数达到最大并且叶子结点从左到右依次排列，那么这颗二叉树为完全二叉树
        // 判断是否是完全二叉树，对左右子树后续遍历并计算结果
        if (root == nullptr)
        {
            return 0;
        }

        TreeNode* left_node = root->left;
        TreeNode* right_node = root->right;

        int left_depth = 0;
        int right_depth = 0;

        while (left_node != nullptr)
        {
            left_depth++;
            left_node = left_node->left;
        }

        while (right_node != nullptr)
        {
            right_depth++;
            right_node = right_node->right;
        }

        if (left_depth == right_depth)
        {
            return (2 << left_depth) - 1;
        }

        int left_nodes = countNodes(root->left);
        int right_nodes = countNodes(root->right);

        return left_nodes + right_nodes + 1;
    }
};
// @lc code=end

