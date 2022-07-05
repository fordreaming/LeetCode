/*
 * @lc app=leetcode.cn id=2129 lang=cpp
 *
 * [2129] 将标题首字母大写
 */

// @lc code=start
class Solution {
public:
    string capitalizeTitle(string title) {
        // all chars to lower
        string res = title;
        res.push_back(' ');

        int l = 0;   // word edge [l, r)
        int r = 0;

        int n = res.size();

        while(r < n) {
            while(res[r] != ' ') {
                r++;
            }

            if(r - l >= 2) {
                if(res[l] >= 'a' && res[l] <= 'z') {
                    res[l] = toupper(res[l]);
                }
                l++;
            }

            while(l < r) {
                if(res[l] >= 'A' && res[l] <= 'Z') {
                    res[l] = tolower(res[l]);
                }
                l++;
            }
            r++;
            l = r;
        }

        res.pop_back();        
        return res;
    }
};
// @lc code=end

