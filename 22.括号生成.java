/*
 * @lc app=leetcode.cn id=22 lang=java
 *
 * [22] 括号生成
 */

// @lc code=start

import java.util.LinkedList;
import java.util.List;

class Solution {
    List<String> result=new LinkedList<>();
    public List<String> generateParenthesis(int n) {
        StringBuilder now=new StringBuilder();
        dfs(n,0,0,now);

        return result;
    }

    void dfs(int n,int left,int right,StringBuilder now){
        if(now.length()==n*2){
            result.add(now.toString());
            return;
        }

        /*
         * 明确：
         * 什么时候可以添加左括号：左括号的总数小于所需要的总的括号数时
         * 什么时候可以添加右括号：右括号的总数小于左括号时
         * 
         * 必做：每次dfs完要回溯，也就是撤销操作
         */
        if(left<n){
            now.append('(');
            dfs(n,left+1,right,now);
            now.deleteCharAt(now.length()-1);
        }
        if(left>right){
            now.append(')');
            dfs(n,left,right+1,now);
            now.deleteCharAt(now.length()-1);
        }
    }
}
// @lc code=end

