/*
 * @lc app=leetcode.cn id=78 lang=java
 *
 * [78] 子集
 */

// @lc code=start

import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;


class Solution {
    List<List<Integer>> result=new LinkedList<>();

    public List<List<Integer>> subsets_permute(int[] nums) {
        int n=nums.length;
        boolean[] used=new boolean[n];
        List<Integer> now=new LinkedList<Integer>();
        dfs_permute(nums,n,now,used);

        //使用set进行去重！注意set实例化是用的hashset！
        Set<List<Integer>> set=new HashSet<>(result);
        //将set转化为list
        result = new LinkedList<>(set);
        //返回结果
        return result;
    }

    void dfs_permute(int[] nums,int n,List<Integer> now,boolean[] used){
        if(now.size()<=n){
            //这么添加添加的是now的引用，会随着后续的变化而变化，所以要创建一个副本（相当于复制一份）
            //result.add(now);
            List<Integer> newlist=new LinkedList<>(now);
            Collections.sort(newlist);
            result.add(newlist);
        }

        for(int i=0;i<n;i++){
            if(!used[i]){
                used[i]=true;
                now.add(nums[i]);
                dfs_permute(nums, n, now, used);

                //回溯，撤销选择
                used[i]=false;
                now.remove(now.size()-1);
            }
        }
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<Integer> now=new LinkedList<Integer>();
        dfs(nums,0,now);

        return result;
    }

    void dfs(int[] nums,int start,List<Integer> now){
        result.add(new LinkedList<>(now));

        for(int i=start;i<nums.length;i++){
            //选择当前元素的情况
            now.add(nums[i]);
            dfs(nums,i+1,now);

            //撤销这一次的选择（不选择当前元素的情况）
            now.remove(now.size()-1);
            //dfs(nums,i+1,now);
        }
    }
}
// @lc code=end

