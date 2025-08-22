/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        int hour,minute;
        
        function<void(int, int, int, int)> backtrack = [&](int index, int count, int hour, int minute) {
            if (hour > 11 || minute > 59) return;

            if (count == turnedOn) {
                res.push_back(to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute));
                return;
            }

            for (int i = index; i < 10; i++) {
                if (i < 4)
                    backtrack(i + 1, count + 1, hour | (1 << i), minute);
                else
                    backtrack(i + 1, count + 1, hour, minute | (1 << (i - 4)));
            }
        };

        backtrack(0, 0, 0, 0);
        return res;
    }
};
// @lc code=end

