// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <algorithm>
#include "commoncppproblem343.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    // 1、动态规划
    // 1) 确定dp数组及下标的含义
    //    分拆数字i可以得到的最大乘积dp[i]
    // 2) 递推关系式
    // dp[j] = i * (j-i);  0 < i < j
    // dp[j] = i * dp[j-i]
    // 3) 初始化
    // dp[1] = 1;
    // dp[2] = 1;
    // dp[3] = 2;
    // 4) 确定遍历顺序
    // 从小到大递推
    // 5）验证值
    // dp[4] = 4
    // dp[5] = 6
    // dp[6] = 9
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;

        for (size_t i = 3; i <= n; i++)
        {
            for (size_t j = 1; j < i; j++)
            {
                // dp[i] = max(dp[i], max(j * dp[i - j], j* (i-j)));
                int temp = max(j * dp[i - j], j* (i-j));
                dp[i] = max(dp[i], temp);
            }
        }
        
        return dp[n];
    }
};
// @lc code=end

