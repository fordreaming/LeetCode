// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem695.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // dfs
        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        int result = 0;

        vector<vector<bool>> used(rows, vector<bool>(cols, false));

        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                if (!used[i][j] && grid[i][j] == 1)
                {
                    result++;
                    int area = 0;
                    bfs(grid, used, i, j, area);
                    if (area > maxArea)
                    {
                        maxArea = area;
                    }
                }
            }
        }
        

        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& used, int row, int col, int& maxArea)
    {
        if (used[row][col] || grid[row][col] == 0)
        {
            return;
        }

        used[row][col] = true;
        maxArea++;
        
        for (size_t i = 0; i < 4; i++)
        {
            int nxtRow = row + dir[i][0];
            int nxtCol = col + dir[i][1];

            if (nxtRow < 0 || nxtRow >= grid.size() || nxtCol < 0 || nxtCol >= grid[0].size())
            {
                continue;
            }

            dfs(grid, used, nxtRow, nxtCol, maxArea);
        }
    }

    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& used, int row, int col, int& maxArea)
    {
        queue<pair<int, int>> que{};
        que.push({row, col});
        used[row][col] = true;
        maxArea++;

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

                if (nxtRow < 0 || nxtRow >= grid.size() || nxtCol < 0 || nxtCol >= grid[0].size())
                {
                    continue;
                }
                    
                if (!used[nxtRow][nxtCol] && grid[nxtRow][nxtCol] == 1)
                {
                    que.push({nxtRow, nxtCol});
                    used[nxtRow][nxtCol] = true;
                    maxArea++;
                }
            }
        }
        
    }

};

// @lc code=end

