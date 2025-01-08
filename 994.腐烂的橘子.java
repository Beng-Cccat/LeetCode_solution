/*
 * @lc app=leetcode.cn id=994 lang=java
 *
 * [994] 腐烂的橘子
 */

// @lc code=start

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
    public int orangesRotting(int[][] grid) {
        //初始化时间
        int[][] time=new int[grid.length][grid[0].length];
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==0)
                    time[i][j]=-1;
                
                else
                    time[i][j]=Integer.MAX_VALUE;
            }
        }
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==2)
                    dfs(grid,time,i,j,0);
            }
        }
        print(grid);
        print(time);
        int max=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==1)
                    return -1;
                max=Math.max(max,time[i][j]);
            }
        }
        return max;
    }
    void dfs(int[][] grid,int[][] time,int r,int c,int currenttime){
        if(!inArea(grid,r,c))
            return;
        if(grid[r][c]==0)
            return;
        if(grid[r][c]==2&&currenttime>=time[r][c])
            return;

        grid[r][c]=2;
        time[r][c]=currenttime;
        print(time);
        dfs(grid,time,r+1,c,currenttime+1);
        dfs(grid,time,r-1,c,currenttime+1);
        dfs(grid,time,r,c+1,currenttime+1);
        dfs(grid,time,r,c-1,currenttime+1);
    }
    boolean inArea(int[][] grid,int r,int c){
        if(r<0||r>=grid.length||c<0||c>=grid[0].length)
            return false;
        return true;
    }
    void print(int[][] grid){
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                System.out.print(grid[i][j]);
                System.out.print(' ');
            }
            System.out.println();
        }
    }
}
// @lc code=end

