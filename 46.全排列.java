/*
 * @lc app=leetcode.cn id=46 lang=java
 *
 * [46] 全排列
 */

// @lc code=start

import java.util.LinkedList;
import java.util.List;

class Solution {
    /*
     * 动态规划只需要求我们评估最优解是多少，最优解对应的具体解是什么并不要求。因此很适合应用于评估一个方案的效果；
     * 回溯算法可以搜索得到所有的方案（当然包括最优解），但是本质上它是一种遍历算法，时间复杂度很高。
     * 
     * 每一个结点表示了求解全排列问题的不同的阶段，这些阶段通过变量的「不同的值」体现，这些变量的不同的值，称之为「状态」；
     * 使用深度优先遍历有「回头」的过程，在「回头」以后， 状态变量需要设置成为和先前一样 ，因此在回到上一层结点的过程中，需要撤销上一次的选择，这个操作称之为「状态重置」；
     * 深度优先遍历，借助系统栈空间，保存所需要的状态变量，在编码中只需要注意遍历到相应的结点的时候，状态变量的值是正确的，具体的做法是：往下走一层的时候，path 变量在尾部追加，而往回走的时候，需要撤销上一次的选择，也是在尾部操作，因此 path 变量是一个栈；
     * 深度优先遍历通过「回溯」操作，实现了全局使用一份状态变量的效果。
     * 
     * 设计状态变量：
     * 首先这棵树除了根结点和叶子结点以外，每一个结点做的事情其实是一样的，即：在已经选择了一些数的前提下，在剩下的还没有选择的数中，依次选择一个数，这显然是一个 递归 结构；
     * 递归的终止条件是： 一个排列中的数字已经选够了 ，因此我们需要一个变量来表示当前程序递归到第几层，我们把这个变量叫做 depth，或者命名为 index ，表示当前要确定的是某个全排列中下标为 index 的那个数是多少；
     * 布尔数组 used，初始化的时候都为 false 表示这些数还没有被选择，当我们选定一个数的时候，就将这个数组的相应位置设置为 true ，这样在考虑下一个位置的时候，就能够以 O(1) 的时间复杂度判断这个数是否被选择过，这是一种「以空间换时间」的思想。

     */
    List<List<Integer>> result=new LinkedList<>();
    public List<List<Integer>> permute(int[] nums) {
        int n=nums.length;
        boolean[] used=new boolean[n];
        List<Integer> now=new LinkedList<Integer>();
        dfs(nums,n,now,used);

        return result;
    }

    void dfs(int[] nums,int n,List<Integer> now,boolean[] used){
        if(now.size()==n){
            //这么添加添加的是now的引用，会随着后续的变化而变化，所以要创建一个副本（相当于复制一份）
            //result.add(now);
            result.add(new LinkedList<>(now));
            return;
        }

        for(int i=0;i<n;i++){
            if(!used[i]){
                used[i]=true;
                now.add(nums[i]);
                dfs(nums, n, now, used);

                //回溯，撤销选择
                used[i]=false;
                now.remove(now.size()-1);
            }
        }
    }
}
// @lc code=end

