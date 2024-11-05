// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem797.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res{};
    vector<int> path{};

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // 深度优先搜索
        // 递归法
        path.push_back(0);
        dfs(graph, 0, graph.size()-1);
        return res;
    }

    void dfs(vector<vector<int>>& graph, int curIdx, int n)
    {
        if (curIdx == n)
        {
            res.push_back(path);
            return;
        }

        for (size_t i = 0; i < graph[curIdx].size(); i++)
        {
            path.push_back(graph[curIdx][i]);
            dfs(graph, graph[curIdx][i], n);
            path.pop_back();
        }
        
    }

};
// @lc code=end

