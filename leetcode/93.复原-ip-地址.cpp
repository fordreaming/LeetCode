// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem93.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> res{};
    string path{};

    vector<string> restoreIpAddresses(string s) {
        backTracking(s, 0, 0);

        return res;
    }

    void backTracking(string& s, int start_idx, int dotNum)
    {
        if (dotNum == 3)
        {
            // [start_idx, s.size() - 1]，加入结果
            if (isValidIp(s, start_idx, s.size() - 1))
            {
                res.push_back(s);
            }

            return;
        }
        

        for (size_t i = start_idx; i < s.size(); i++)
        {
            if (isValidIp(s, start_idx, i))
            {
                s.insert(s.begin() + i + 1, '.');
                dotNum++;
                backTracking(s, i + 2, dotNum);
                dotNum--;

                s.erase(s.begin() + i + 1);       
            }
            else
            {
                break;
            }
        }
    }

    // 判断ip是否有效,如果有效，截取ip, 否则，为空。
    // [start, end]
    bool isValidIp(const std::string& s, int start, int end)
    {
        // 1、开始小于结尾，不合法
        if (start > end)
        {
            return false;
        }
        
        // 2、以0开头，不合法
        if (start != end && s[start] == '0')
        {
            return false;
        }
        
        // 3、大于255不合法
        // 循环判断并计算数字
        int num = 0;
        for (size_t i = start; i <= end; i++)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                return false;
            }
            
            num = (num * 10) + (s[i] - '0');
            if (num > 255)
            {
                return false;
            }
        }
        
        return true;
    }
};
// @lc code=end

