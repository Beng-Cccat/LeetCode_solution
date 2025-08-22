/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        /*
        右边界循环/左边界循环
        */
        unordered_map<char,int> hmap;
        for(int i=0;i<t.size();i++)
            hmap[t[i]]++;

        int less=hmap.size();
        int left=0,right=0;
        int ans_left=-1,ans_right=s.size();
        for(;left<s.size();left++){
            //当前窗口不满足，扩张右边界
            while(less>0&&right<s.size()){
                if(hmap.find(s[right])!=hmap.end()){
                    hmap[s[right]]--;
                    if(hmap[s[right]]==0){
                        less--;
                    }
                }
                right++;
            }
            //如果窗口满足，更新答案
            if(!less){
                if(right-left<ans_right-ans_left){
                    ans_right=right;
                    ans_left=left;
                }
            }
            //移出左边界
            if(hmap.find(s[left])!=hmap.end()){
                if(hmap[s[left]]==0){
                    less++;
                }
                hmap[s[left]]++;
            }

        }
        return ans_left == -1 ? "" : s.substr(ans_left, ans_right - ans_left);
    }
};
// @lc code=end

