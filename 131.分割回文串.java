/*
 * @lc app=leetcode.cn id=131 lang=java
 *
 * [131] 分割回文串
 */

// @lc code=ptr

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

class Solution {
    /*
     * 1. 每对相邻字符之间有个逗号，看逗号选还是不选：是否要把 s[i] 当成分割出的子串的最后一个字符，注意 s[n−1] 一定是最后一个字符，一定要选
     * 2. 枚举字串结束位置
     */
    List<List<String>> result=new LinkedList<>();
    Boolean[][] isback;
    int n;
    String s;
    public List<List<String>> partition(String s) {
        List<String> path=new ArrayList<>();
        //转换成全局变量，使其不用传递也可以被其他函数使用
        this.s=s;
        n=s.length();
        isback=new Boolean[n][n];
        //初始化
        for(int i=0;i<n;i++){
            Arrays.fill(isback[i], true);
        }
        //判断每两个数之间的值是否为回文串
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                //这里isback[i][j]会使用isback[i+1][j-1]，如果从左到右初始化的话，使用i的时候i+1还没有初始化，所以会导致错误，需要从右到左才能避免这个问题
                isback[i][j]=isback[i+1][j-1]&&s.charAt(i)==s.charAt(j);
            }
        }

        //开始dfs
        dfs(0,0,path);

        return result;
    }

    void dfs(int i,int ptr,List<String> path){
        if(ptr==n){
            result.add(new ArrayList<>(path));
            return;
        }

        //不要逗号，相当于继续查看
        if(ptr<n-1)
            dfs(i,ptr+1,path);
        
        //要逗号，相当于分割字符串
        if(isback[i][ptr]){
            path.add(s.substring(i,ptr+1));
            dfs(ptr+1,ptr+1,path);

            //回溯，恢复现场
            path.remove(path.size()-1);
        }
    }
}
// @lc code=end

