// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem62.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    // 1、抽象为一颗二叉树，而叶子节点就是终点，会超时；遍历2^(m + n -1) - 1节点个数
    // 2、动态规划
    // 1) 确定dp数组及i的含义：
    //    dp[i][j]表示从(0, 0)到(i, j)不同路径的个数；
    // 2) 递推关系式
    //    dp[i][j] = dp[i-1][j] + dp[i][j-1]

    // 3）初始化
    //    dp[0][0] = 1;
    //    dp[1][0] = 1;
    //    dp[0][1] = 1;
    //    第一行和第一列初始化为1

    // 4) 递推方向
    // 从上到下，从左到右

    // 5) 推导值并进行验证
    //  dp[2][0] = 1;
    //

    // 3、动态规划（滚动数组)，用一维数组表示

    // 4、数论
    // 因为只能从左到右，从上到下，所以可以转化为数论知识
    // m+n-2个数中，取m-1个数的组合总数
    // ((m+n-2)*(m+n-3)...n)/(m-1)!

    // i:[1, m]
    // j: [1, n];

    int uniquePaths(int m, int n) {
        long long res = 1;

        for (size_t x = 1, y = n; x < m; x++, y++)
        {
            res = (res*y)/x;
        }
        
        return res;
    }
};
// @lc code=end

