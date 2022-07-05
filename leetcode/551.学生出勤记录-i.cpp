/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        int absent_num = 0;
        int lates = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'A') {
                absent_num++;
                if(absent_num > 1) {
                    return false;
                }
            }
            
            if(s[i] == 'L') {
                lates++;
                if(lates >= 3) {
                    return false;
                }
            } else {
                lates = 0;
            }
        }

        return true;
    }
};
// @lc code=end

