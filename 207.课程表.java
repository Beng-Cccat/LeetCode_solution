/*
 * @lc app=leetcode.cn id=207 lang=java
 *
 * [207] 课程表
 */

// @lc code=start

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

class Solution {
    /*
     * 把一个 有向无环图 转成 线性的排序 就叫 拓扑排序
     * 入度 & 出度
     */
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        //注意什么时候用List，什么时候用int[]
        //个人感觉需要增添东西的时候用list，如果只是一个映射关系的话就用int[]就可以
        Map<Integer,List<Integer>> courses=new HashMap<>();
        int[] front=new int[numCourses];
        for(int[] pair:prerequisites){
            //先学pair[1]（key）再学pair[0]（value）
            int value=pair[0];
            int key=pair[1];
            if(!courses.containsKey(key)){
                courses.put(key,new ArrayList<>());
            }
            courses.get(key).add(value);
            front[value]++;
        }

        //Queue的实例化是用的LinkedList！！
        Queue<Integer> canstudy=new LinkedList<>();

        int studied=0;
        for(int i=0;i<numCourses;i++){
            if(front[i]==0)
                canstudy.add(i);
        }

        while(!canstudy.isEmpty()){
            studied++;
            int currentcourse=canstudy.poll();
            List<Integer> backcourse=courses.get(currentcourse);
            //这里要处理空指针
            if(backcourse==null)
                continue;
            for(Integer i:backcourse){
                front[i]--;
                if(front[i]==0){
                    canstudy.add(i);
                }
            }
        }

        if(studied==numCourses)
            return true;
        else
            return false;
    }
}
// @lc code=end

