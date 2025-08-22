/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //特殊情况
        if(digits.empty())return {};

        vector<string> result;

        //记录每一次的回溯
        string path;

        //创建一个映射
        unordered_map<char,string> phoneMap={
            {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
            {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}
        };
        
        //匿名函数
        function<void(int)> backtrack=[&](int index){
            //终止条件
            if(index==digits.size()){
                result.push_back(path);
                return;
            }

            //穷举每一个可能的字符
            for(char c:phoneMap[digits[index]]){
                path.push_back(c);  //加进去
                backtrack(index+1); //递归下一层
                path.pop_back();    //撤销选择
            }
        };

        backtrack(0);

        return result;
    }
};
// @lc code=end

