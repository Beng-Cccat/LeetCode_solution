/*
 * @lc app=leetcode.cn id=17 lang=java
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.lang.Character;

class Solution {
    List<String> result=new LinkedList<>();
    Map<Character,String> hsmap=new HashMap<>();
    public List<String> letterCombinations(String digits) {
        //做限定
        /*
         * 注意：digits==null和digits.length()==0是两种不同的情况
         * digits==null表示 digits 变量没有被初始化，或者被显式设置为 null。在这种情况下，digits 变量没有指向任何有效的 String 对象
         * digits.length()==0表示 digits 是一个有效的 String 对象，但它的内容是空的，即它不包含任何字符；这是一个合法的字符串对象，只是长度为零
         */
        if(digits==null||digits.length()==0)
            return result;

        StringBuilder now=new StringBuilder();

        hsmap.put('2', "abc");
        hsmap.put('3', "def");
        hsmap.put('4', "ghi");
        hsmap.put('5', "jkl");
        hsmap.put('6', "mno");
        hsmap.put('7', "pqrs");
        hsmap.put('8', "tuv");
        hsmap.put('9', "wxyz");

        dfs(digits,0,now);
        return result;
    }

    void dfs(String digits,int start,StringBuilder now){
        if(start==digits.length()){
            result.add(now.toString());
            return;
        }

        //这里不是用的int，而是直接用的字符进行索引
        int n=hsmap.get(digits.charAt(start)).length();
        for(int i=0;i<n;i++){
            now.append(hsmap.get(digits.charAt(start)).charAt(i));
            dfs(digits,start+1,now);

            //回溯，撤销相关操作
            now.deleteCharAt(now.length()-1);
        }
    }
}
// @lc code=end

