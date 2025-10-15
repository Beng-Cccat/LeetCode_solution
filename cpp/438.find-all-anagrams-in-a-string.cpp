/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> hp;
        unordered_map<char,int> inclu;
        vector<int> res;
        int start=0;

        if(s.size()<p.size())
            return {};

        for(char c:p)
            hp[c]++;

        //或者是固定窗口大小为p.size()
        for(int i=0;i<s.size();i++){
            //不含有这元素
            if(hp.find(s[i])==hp.end()){
                inclu.clear();
                start=i+1;
                continue;
            }
            //已经饱和
            if(hp[s[i]]==inclu[s[i]]){
                while(s[start]!=s[i]){
                    inclu[s[start]]--;
                    start++;
                }
                start++;
                continue;
            }
            
            //增加计数
            inclu[s[i]]++;

            //满足条件
            if(i-start+1==p.size()){
                res.push_back(start);
                inclu[s[start]]--;
                start++;
            }

        }
        return res;
    }
};
// @lc code=end

