// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem463.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (size_t k = 0; k < 4; k++)
                    {
                        int nxtRow = dir[k][0] + i;
                        int nxtCol = dir[k][1] + j;
                        
                        if (nxtRow < 0 || nxtRow >= rows || nxtCol < 0 || nxtCol >= cols || grid[nxtRow][nxtCol] == 0)
                        {
                            res++;
                        }
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

