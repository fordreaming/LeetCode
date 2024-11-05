// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <unordered_map>
#include "commoncppproblem17.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> res{};
    std::string path{};

    std::unordered_map<int, std::string> letterMap{{2, "abc"},
                                                   {3, "def"}, 
                                                   {4, "ghi"}, 
                                                   {5, "jkl"}, 
                                                   {6, "mno"}, 
                                                   {7, "pqrs"}, 
                                                   {8, "tuv"}, 
                                                   {9, "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
        {
            return res;
        }
        
        backTracking(digits, 0);
        return res;
    }

    void backTracking(const std::string& digits, int idx)
    {
        if (digits.size() == idx)
        {
            res.push_back(path);
            return;
        }

        // 获取字符串
        // 1、获取对应的数字
        int num = digits[idx] - '0';    
        // 2、根据数字获取对应的字符串
        std::string character = letterMap[num];
        for (size_t i = 0; i < character.size(); i++)
        {
            path.push_back(character[i]);
            backTracking(digits, idx + 1);
            path.pop_back();
        }
    }
};
// @lc code=end

