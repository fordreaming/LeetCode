// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem131.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> res{};
    vector<string> path{};

    vector<vector<string>> partition(string s) 
    {
        backTracking(s, 0);

        return res;
    }

    void backTracking(const std::string& str, int start_idx)
    {
        // 迭代终止条件
        if (start_idx == str.size())
        {
            res.push_back(path);
            return;
        }

        for (size_t i = start_idx; i < str.size(); i++)
        {
            if (isPalidrome(str, start_idx, i))
            {
                std::string sub_str = str.substr(start_idx, i - start_idx + 1);
                path.push_back(sub_str);
                backTracking(str, i + 1);
                int test = 0;
                path.pop_back();
            }
            else 
            {
                continue;
            }
        }
    }

    // [start, end]
    bool isPalidrome(const std::string& str, int start, int end)
    {
        for (size_t i = start, j = end; i < j; i++, j--)
        {
            if (str[i] != str[j])
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

