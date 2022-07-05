/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //generate all parenthesis and remove invalid
        vector<string> parenthesises;

        std::string cur;
        vector<string> results;
        int left_brance = 0;
        int right_brance = 0;

        GenerateAll(cur, 2*n, left_brance, right_brance, results);
        return results;
    }

    void GenerateAll(string& cur, int n, int& left_brance, int& right_brance, vector<string>& resluts) {
        if(n == cur.size()) {
            if(IsValidParenthesis(cur)) {
                resluts.emplace_back(cur);
            }
            return;
        }

        if(left_brance < n) {
            cur += "(";
            left_brance++;
        }

        GenerateAll(cur, n, left_brance, right_brance, resluts);
        cur.pop_back();

        if(right_brance < left_brance) {
            cur += ")";
            right_brance++;
        }

        GenerateAll(cur, n, left_brance, right_brance, resluts);
        cur.pop_back();
    }

    bool IsValidParenthesis(const std::string& cur) {
        int balance = 0;
        for(const char& ch : cur) {
            if(ch == '(') {
                balance++;
            } else {
                balance--;
            }

            if(balance < 0) {
                return false;
            }
        }
        
        if(balance != 0) {
            return false;
        } 
        
        return true;
    }
};
// @lc code=end

