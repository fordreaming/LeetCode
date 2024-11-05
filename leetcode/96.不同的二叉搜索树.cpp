// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem96.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        // 1.确定dp数组及i的含义
        // dp[i]表示以1~i为头节点所组成的不同的二叉搜索树的个数；
        // 2.递推公式
        // dp[i] += dp[j-1]* dp[i-j] j:[1, n]
        // 3.dp数组如何初始化
        // dp[0] = 1;
        // dp[1] = 1;
        // 4. 确定遍历顺序
        // dp[i] += dp[j-1]* dp[i-j]
        // 结点i的状态依靠i之前节点的状态
        //  
        // 5. 举例推导dp数组
        // dp[0] = 1;
        // dp[1] = 1;
        // dp[2] = 2;
        // dp[3] = 5;
        // dp[4] = ?

        // 2. 数学抽象卡特兰数，记住该公式
        // c[0] = 1;
        // c[n+1] = 2*(2n + 1)/(n + 2) * C[n]

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = 1; j <= i; j++)
            {
                dp[i] += dp[j-1]* dp[i-j];
            }
        }

        return dp[n];
    }
};
// @lc code=end

