// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem746.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    // 1、动态规划
    // 1) dp[i]表示到达dp[i]所花费的最小体力
    // 2）递推关系式： dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])
    // 3) 初始化
    //   dp[0] = 0;
    //   dp[1] = 0;

    // 4) 遍历顺序： dp[i]由dp[i-1]和dp[i-2]推出
    // 5) 举例推导dp数组

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n + 1, 0);

        for (size_t i = 2; i <= cost.size(); i++)
        {
            int temp1 = dp[i-1]+ cost[i-1];
            int temp2 = dp[i-2] + cost[i-2];

            dp[i] = min(temp1, temp2);

            // dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        
        int res = dp[n];
        
        return dp[n];
    }
};
// @lc code=end

