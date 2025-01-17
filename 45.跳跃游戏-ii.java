/*
 * @lc app=leetcode.cn id=45 lang=java
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    public int jump(int[] nums) {
        /*
         * 贪心算法：顺藤摸瓜
         * 从前往后更新，找能跳到最远的那一个，然后跳到他的位置
         */
        int n=nums.length;
        if(n==1)
            return 0;
        int maxPosition=0;
        int end=0;    //到达end时进行下一次跳跃，所以初始化为0而不是nums[0]
        int steps=0;
        //因为最后一个位置不是起跳点，所以不需要遍历，可以通过当前最远到达的范围进行是否能到达最后一个位置的判断
        for(int i=0;i<n-1;i++){
            maxPosition=Math.max(maxPosition,i+nums[i]);
            if(i==end){
                steps++;
                end=maxPosition;
            }
            //此时已经可以提前判断能够到达最后一个元素所以直接break就行
            if(end>=n-1)
                break;
        }
        return steps;
    }


    public int jump_slow(int[] nums) {
        /*
         * 从前往后更新
         * jumpnum[i]表示到第i个索引所需的最小步数，因为是从前面开始跳的，所以想到了从前往后更新
         * 类似“找公因数”，就是从1、2、3然后不断地给后面的值赋值为true或者false
         * 比较慢，性能差
         */
        int n=nums.length;
        int[] jumpnum=new int[n];
        Arrays.fill(jumpnum, Integer.MAX_VALUE);
        jumpnum[0]=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                if(i+j>=n)
                    break;
                jumpnum[i+j]=Math.min(jumpnum[i]+1,jumpnum[i+j]);
            }
        }
        return jumpnum[n-1];
    }
}
// @lc code=end

