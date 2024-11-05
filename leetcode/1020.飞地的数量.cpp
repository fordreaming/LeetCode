// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1020.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>> temp1{{0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
        // grid = temp1;

        int enclave_num = 0;

        vector<vector<bool>> used(m, vector<bool>(n, false));

        // 1、从左边界和右边界遍历，遇到陆地标记成海洋
        int count = 0;
        for (size_t i = 0; i < m; i++)
        {
            if (grid[i][0] == 1 && used[i][0] == false)
            {
                bfs(grid, used, i, 0, count);
            }
            

            if (grid[i][n - 1] == 1 && used[i][n-1] == false)
            {
                bfs(grid, used, i, n-1, count);
            }
        }

        // 2、从上边界和下边界遍历，遇到陆地标记成海洋
        for (size_t i = 0; i < n; i++)
        {
            if (grid[0][i] == 1 && used[0][i] == false)
            {
                bfs(grid, used, 0, i, count);
            }
            
            if (grid[m-1][i] == 1 && used[m-1][i] == false)
            {
                bfs(grid, used, m-1, i, count);
            }
        }
        
        // 3、重新遍历，统计1的个数
        count = 0;
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                int count1 = 0;
                if (grid[i][j] == 1 && used[i][j] == false)
                {
                    bfs(grid, used, i, j, count1);
                    count = std::max(count, count1);
                }
            }
            
        }
    
        return count;
    }

    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& used, int row, int col, int& count)
    {
        queue<pair<int, int>> que{};
        que.push({row, col});

        count++;
        // grid[row][col] = 0;
        used[row][col] = true;

        while (!que.empty())
        {
            pair<int, int> cur_pos = que.front();
            que.pop();

            for (size_t i = 0; i < 4; i++)
            {
                int nxt_row = cur_pos.first + dir[i][0];
                int nxt_col = cur_pos.second + dir[i][1];

                if (nxt_row < 0 
                        || nxt_row >= grid.size() 
                        || nxt_col < 0 
                        || nxt_col >= grid[0].size()
                )
                {
                    continue;
                }
                
                if (grid[nxt_row][nxt_col] == 1 && used[nxt_row][nxt_col] == false)
                {
                    count++;
                    // grid[nxt_row][nxt_col] = 0;
                    used[nxt_row][nxt_col] = true;
                    que.push({nxt_row, nxt_col});
                }   
            }
        }
    }
};
// @lc code=end

