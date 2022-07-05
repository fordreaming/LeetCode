/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        bool ret = false;
        if(s.size() != goal.size()) {
            return ret;
        }

        if(s == goal) {
            unordered_set<char> sets;
            for(char ch: s) {
                if(sets.find(ch) == sets.end()) {
                    sets.insert(ch);
                } else {
                    return true;
                }
            }
            return false;
        }

        int diff_num = 0;
        vector<int> diff_idx;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] != goal[i]) {
                diff_num++;
                diff_idx.emplace_back(i);
            }
        }

        std::cout << "diff num: " << diff_num << std::endl;

        if(diff_num == 2) {
            if(s[diff_idx[0]] != goal[diff_idx[1]] ||
            s[diff_idx[1]] != goal[diff_idx[0]]) 
            {
                return false;
            }

            return true;
        }

        return false;
    }
};
// @lc code=end

