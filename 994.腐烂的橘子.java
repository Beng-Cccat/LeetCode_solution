/*
 * @lc app=leetcode.cn id=994 lang=java
 *
 * [994] 腐烂的橘子
 */

// @lc code=start

import java.util.LinkedList;
import java.util.Queue;

class Solution {
    /*
     * 注意这里不能用012表示他们的状态，怎么说呢
     * 因为深度优先遍历，可能第一条线上的时间是对的
     * 后面遍历的时候会默认这一条线上的句子也为初始坏掉的，就会导致时间计算不准确
     * 所以要进行改动：先定位初始坏掉的橘子
     * 
     * 不行不行，从一个点延伸出去的各个线也会互相影响！
     * 
     * 另建一个数组用来放置时间？
     * 
     * 结论：不是所有的都能用dfs解决的（haha，一个下午没干出来）
     */
    /*
     * 同时扩散：bfs
     */
    public int orangesRotting(int[][] grid) {
        int row=grid.length;
        int col=grid[0].length;
        int fresh=0;
        Queue<int[]> neworange=new LinkedList<>();
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++){
                if(grid[i][j]==2)
                    neworange.add(new int[]{i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        if(fresh==0)
            return 0;
        int minute=-1;
        while(!neworange.isEmpty()){
            int num=neworange.size();
            minute++;
            for(int i=0;i<num;i++){
                int[] orange=neworange.poll();
                int r=orange[0];
                int c=orange[1];

                //开始增加
                if(r-1>=0&&grid[r-1][c]==1){
                    grid[r-1][c]=2;
                    fresh--;
                    neworange.add(new int[]{r-1,c});
                }
                if(r+1<row&&grid[r+1][c]==1){
                    grid[r+1][c]=2;
                    fresh--;
                    neworange.add(new int[]{r+1,c});
                }
                if(c-1>=0&&grid[r][c-1]==1){
                    grid[r][c-1]=2;
                    fresh--;
                    neworange.add(new int[]{r,c-1});
                }
                if(c+1<col&&grid[r][c+1]==1){
                    grid[r][c+1]=2;
                    fresh--;
                    neworange.add(new int[]{r,c+1});
                }
            }
        }
        
        return fresh==0?minute:-1;
    }
}
// @lc code=end

