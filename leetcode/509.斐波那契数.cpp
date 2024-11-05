// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem509.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        // 动规五部曲
        // 1、确定dp数组及下标的含义
        // dp[i]表示第i项的值
        // 2、确定递推公式
        // 状态转移方程：dp[i] = dp[i-1] + dp[i-2]
        // 3、dp数组如何初始化
        // dp[0] = 0;
        // dp[1] = 1;
        // 4、确定遍历顺序
        // 从递推公式中可以看出遍历顺序是从前往后
        // 5、举例推导数组
        // 0、1、1、2、3、5、8、13、21、34
        if (n <= 0)
        {
            return n;
        }
        
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for (size_t i = 2; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};
// @lc code=end

