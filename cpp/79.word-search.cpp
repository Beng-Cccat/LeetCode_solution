/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist_fail(vector<vector<char>>& board, string word) {
        int row=board.size(),col=board[0].size();
        vector<vector<bool>> used(row,vector<bool>(col,false));
        bool result=false;
        int x=0,y=0;
        string str;

        function<void(int)> backtrack=[&](int index){
            //终止条件
            if(index==word.size()){
                if(str==word)
                    result=true;
                return;
            }

            //回溯
            for(int i=x;i<row;i++){
                for(int j=y;j<col;j++){
                    if(i-1>=0&&!used[i-1][j]&&board[i-1][j]==word[index]){
                        str.push_back(board[i-1][j]);
                        used[i-1][j]=true;
                        backtrack(index+1);
                        used[i-1][j]=false;
                        str.pop_back();
                    }
                    if(i+1<row&&!used[i+1][j]&&board[i+1][j]==word[index]){
                        str.push_back(board[i+1][j]);
                        used[i+1][j]=true;
                        backtrack(index+1);
                        used[i+1][j]=false;
                        str.pop_back();
                    }
                    if(j-1>=0&&!used[i][j-1]&&board[i][j-1]==word[index]){
                        str.push_back(board[i][j-1]);
                        used[i][j-1]=true;
                        backtrack(index+1);
                        used[i][j-1]=false;
                        str.pop_back();
                    }
                    if(j+1<col&&!used[i][j+1]&&board[i][j+1]==word[index]){
                        str.push_back(board[i][j+1]);
                        used[i][j+1]=true;
                        backtrack(index+1);
                        used[i][j+1]=false;
                        str.pop_back();
                            
                    }
                }
            }
            
        };

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    x=i;
                    y=j;
                    str.push_back(word[0]);
                    backtrack(0);
                    if(result)
                        return result;
                }
            }
        }
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size(),col=board[0].size();
        vector<vector<bool>> used(row,vector<bool>(col,false));
        bool result=false;

        function<bool(int,int,int)> backtrack=[&](int i,int j,int index){
            //越界、重复访问或者字符不匹配，剪枝
            if(i<0||i>=row||j<0||j>=col||used[i][j]||board[i][j]!=word[index])
                return false;
            
            //所有字符匹配成功
            if(index==word.size()-1)
                return true;
            
            //这里表示前面没有返回，即在继续查找且找到的过程，所以这里即使用该元素
            used[i][j]=true;

            //横扫上下左右
            bool found= backtrack(i-1,j,index+1)||
                        backtrack(i+1,j,index+1)||
                        backtrack(i,j-1,index+1)||
                        backtrack(i,j+1,index+1);
            
            used[i][j]=false;   //还原状态

            return found;
        };

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(backtrack(i,j,0))
                    return true;
        return false;
    }
};
// @lc code=end

