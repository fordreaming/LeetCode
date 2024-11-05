// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem63.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    // 1、动态规划，如果遇到障碍物，初始化为0
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // 1）、dp[i][j]表示从（0，0）到（i，j)的路径数
        // 2）、递推关系式
        // dp[i][j] = {0}  obstacleGrid[i][j] = 1
        // dp[i][j] = dp[i-1][j] + dp[i][j-1]  obstacleGrid[i][j] = 0
        // 3）、初始化
        // 首行和首列比较特殊为1：
        // 4）、递推顺序
        // 从左到右，从上到下
        // 5）、验证值
        // 如果初始和最终位置有障碍物，那么直接返回0
        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
        {
            return 0;
        }
        
        // 首行初始化
        for (size_t j = 0; j < n; j++)
        {
            if (obstacleGrid[0][j] == 1)
            {
                dp[0][j] = 0;
                continue;
            }
            
            dp[0][j] = 1;
        }
        
        // 首列初始化
        for (size_t i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 1)
            {
                dp[i][0] = 0;
                continue;
            }
            
            dp[i][0] = 1;
        }
        
        for (size_t i = 1; i < m; i++)
        {
            for (size_t j = 1; i < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};
// @lc code=end

