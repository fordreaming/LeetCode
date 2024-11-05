// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem70.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // 动规五部曲
        // 1、确定dp数组及i的含义
        vector<int> dp(n+1, 0);
        // 2、确定递推公式；
        // 3、dp数组初始化
        // 4、确定递推顺序
        // 5、递推数组结果
        // dp[i]表示爬到第i层的方法
        dp[0] = 1;
        dp[1] = 1;

        for (size_t i = 2; i <=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        // 从前向后
        // 1  2   3    4   5
        // 1  2   3    5   8

        return dp[n];
    }
};
// @lc code=end

