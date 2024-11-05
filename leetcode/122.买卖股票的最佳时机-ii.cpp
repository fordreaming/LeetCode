// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem122.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    // 1、贪心法,把利润拆解为每天的利润
    // max_profit = sigma(0, )
    // \sum ^{n}_{i=1}\left( 0,\left( a_{i}-a_{i}\right)\right)

    // 2、动态规划法
    // 1) 确定dp及i的含义
    // dp[i][0]: 表示第i天交易完成，手里没有股票的最大利润；
    // dp[i][1]: 表示第i天交易完成，手里有股票的最大利润；

    // 2) 递推关系式
    // 第i天交易完成，手里没有股票的最大利润，有2种情况：1、第i-1天交易完成后，手里没有股票； 2、第i-1天交易完成后，持有股票，第i天交易完成后，卖出
    // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
    // 第i天交易完成持有股票，1、第i-1天手里持有股票；   2、第i-1天未持有股票，第i天卖入；
    // dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])

    // 3) 初始化
    // dp[0][0] = 0;
    // dp[0][1] = -prices[0]

    // 4) 递推顺序
    // 从小到大
    // 5) 验证值

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (size_t i = 1; i < prices.size(); i++)

        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        
        return dp[n-1][0];
    }
};
// @lc code=end

