// 孤岛的总面积
// 1. 输入矩阵的行数和列数
// 2. 矩阵初始化
// 3. 遍历周边并设置标志
// 4. 从非边缘位置遍历并统计孤岛的面积
#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& used, int row, int col, int& totalArea)
{
    if (grid[row][col] == 0 || used[row][col])
    {
        return;
    }

    used[row][col] = true;
    totalArea++;

    for (size_t i = 0; i < 4; i++)
    {
        int nxtRow = row + dir[i][0];
        int nxtCol = col + dir[i][1];

        if (nxtRow < 0 || nxtRow >= grid.size() || nxtCol < 0 || nxtCol >= grid[0].size())
        {
            continue;
        }

        if (grid[nxtRow][nxtCol] == 1 && !used[nxtRow][nxtCol])
        {
            dfs(grid, used, nxtRow, nxtCol, totalArea);
        }
    }
    
}

int main()
{
    // 1. 输入矩阵的行数和列数
    int rows = 5;
    int cols = 5;

    // cin >> rows >> cols;


    // 2. 矩阵初始化
    vector<vector<int>> grid{{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 0, 0}};
    vector<vector<bool>> used(rows, vector<bool>(cols, false));
    
    // 3. 遍历周边并设置标志
    // 第一列和倒数第一列
    // [row][0]
    // row[cols-1]
    int totalArea = 0;
    for (size_t i = 0; i < rows; i++)
    {
        if (grid[i][0] == 1)
        {
            dfs(grid, used, i, 0, totalArea);
        }

        if (grid[i][cols-1] == 1)
        {
            dfs(grid, used, i, cols-1, totalArea);
        }
        
    }

    // 第一行和倒数第一行
    for (size_t i = 0; i < cols; i++)
    {
        /* code */
        if (grid[0][i] == 1)
        {
            dfs(grid, used, 0, i, totalArea);
        }
        
        if (grid[rows-1][i] == 1)
        {
            dfs(grid, used, rows-1, i, totalArea);
        }
    }
    
    
    // 4. 从非边缘位置遍历并统计孤岛的面积
    int totalAreaOfLonglyIsland = 0;
    for (size_t i = 1; i < rows-1; i++)
    {
        for (size_t j = 1; j < cols-1; j++)
        {
            if (grid[i][j] == 1 && used[i][j] == false)
            {
                dfs(grid, used, i, j, totalAreaOfLonglyIsland);
            }
        }
    }
    
    std::cout << totalAreaOfLonglyIsland;
}