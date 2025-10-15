/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s,int left,int right){
        while(left<right)
            if(s[left++]!=s[right--])
                return false;
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;

        vector<string> tmp;

        function<void(int)> backtrack=[&](int start){
            if(start==s.size()){
                res.push_back(tmp);
                return;
            }

            for(int i=start;i<s.size();i++){
                if(isPalindrome(s,start,i)){
                    tmp.push_back(s.substr(start,i-start+1));
                    backtrack(i+1);
                    tmp.pop_back();
                }
            }
        };

        backtrack(0);
        return res;
    }
};
// @lc code=end

