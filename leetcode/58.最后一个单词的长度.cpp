// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem58.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    // 1.双指针，
    // 从后向前，如果是空格，继续进行搜索；
    // 找到第一个非空格，开始计数；
    // 非空格继续遍历
    // 遇到空格，停止，统计单词长度
    int lengthOfLastWord(string s) {
        int index = s.size() - 1;

        while (s[index] == ' ')
        {
            index--;
        }

        int word_len = 0;
        while (index >= 0 && s[index] != ' ')
        {
            word_len++;
            index--;
        }
        
        return word_len;
    }
};
// @lc code=end

