/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string,int> hmap;
        if(s.size()<10)return res;
        for(int i=0;i<=s.size()-10;i++){
            string temp=s.substr(i,10);
            hmap[temp]++;
        }

        for(auto &[key,count]:hmap){
            if(count>1){
                res.push_back(key);
            }
        }
        return res;
    }
};
// @lc code=end

