/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        //法一：哈希表
        char res;
        unordered_map<char,int> hmap;
        for(int i=0;i<t.size();i++){
            hmap[t[i]]++;
        }
        for(int i=0;i<s.size();i++){
            hmap[s[i]]--;
        }
        for(auto &[key,value]:hmap)
            if(value)
                res=key;
        
        return res;

        //法二：异或（相同的字符异或后会抵消为 0，最后剩下的就是多出的字符）
        //法三：数组计数（由于只涉及小写字母，可以用长度为 26 的数组代替哈希表）
        //法四：ASCII 求和（计算 t 的字符总和减去 s 的字符总和，多出的就是那个字符）
    }
};
// @lc code=end

