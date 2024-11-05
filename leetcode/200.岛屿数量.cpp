// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <queue>
#include "commoncppproblem200.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    // 按照图像坐标系，左上角为(0, 0), row向下变大，col向右变大
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int result = 0;       // 岛屿数量
    

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> used(rows, vector<bool>(cols, false));

        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1' && used[i][j] == false)
                {
                    result++;
                    bfs(grid, used, i, j);
                }
            }
        }
        
        return result;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& used, int row, int col)
    {
        if (used[row][col] || grid[row][col] == '0')
        {
            return;
        }

        used[row][col] = true;

        for (size_t i = 0; i < 4; i++)
        {
            int nxtRow = row + dir[i][0];
            int nxtCol = col + dir[i][1];

            if (nxtRow < 0 || nxtRow >= grid.size() || nxtCol < 0 || nxtCol >= grid[0].size())
            {
                continue;
            }
            
            if (!used[nxtRow][nxtCol] && grid[nxtRow][nxtCol] == '1')
            {
                dfs(grid, used, nxtRow, nxtCol);
            }
            
        }
    }

    void bfs(const vector<vector<char>>& grid, vector<vector<bool>>& used, int row, int col)
    {
        queue<pair<int, int>> que{};
        que.push({row, col});
        used[row][col] = true;

        while (!que.empty())
        {
            pair<int, int> curRowCol = que.front();
            que.pop();

            int curRow = curRowCol.first;
            int curCol = curRowCol.second;

            for (size_t i = 0; i < 4; i++)
            {
                int nxtRow = curRow + dir[i][0];
                int nxtCol = curCol + dir[i][1];

                if(nxtRow < 0 || nxtRow >= grid.size() || nxtCol < 0 || nxtCol >= grid[0].size())
                {
                    continue;
                }
                
                if (!used[nxtRow][nxtCol] && grid[nxtRow][nxtCol] == '1')
                {
                    used[nxtRow][nxtCol] = true;
                    que.push({nxtRow, nxtCol});
                }
            }
        }
    }

};
// @lc code=end

