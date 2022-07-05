/*
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
 */

// @lc code=start
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // no intersection
        // rect1 x1,  y1,  x2,  y2
        // rect2 x1', y1', x2', y2'
        if(rec1[2] <= rec2[0] || rec1[0] >= rec2[2] || rec1[1] >= rec2[3]
            || rec1[3] <= rec2[1]) {
                return false;
            } else {
                return true;
            }
    }
};
// @lc code=end

