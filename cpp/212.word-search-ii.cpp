/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution {
public:
    vector<string> findWords_TLE(vector<vector<char>>& board, vector<string>& words) {
        int row=board.size(),col=board[0].size();
        vector<vector<bool>> used(row,vector<bool>(col,false));
        vector<bool> exist(words.size(),false);
        vector<string> res;
        string word;

        function<bool(int,int,int)> backtrack=[&](int i,int j,int index){
            if(i>=row||i<0||j>=col||j<0||used[i][j]||board[i][j]!=word[index])
                return false;
            
            if(index==word.size()-1)
                return true;

            used[i][j]=true;

            bool found= backtrack(i-1,j,index+1)||
                        backtrack(i+1,j,index+1)||
                        backtrack(i,j-1,index+1)||
                        backtrack(i,j+1,index+1);

            used[i][j]=false;

            return found;
        };

        for(int idx=0;idx<words.size();idx++){
            word=words[idx];
            for(int i=0;i<row;i++)
                for(int j=0;j<col;j++){
                    if(board[i][j]==word[0])
                        if(backtrack(i,j,0)){
                            exist[idx]=true;
                            j=col;
                            i=row;
                        }
                }
        }

        for(int i=0;i<words.size();i++){
            if(exist[i]==true)
                res.push_back(words[i]);
        }
        return res;
    }


    //前缀树
    struct TrieNode{
        bool end;
        string s;
        unordered_map<char,TrieNode*> next;
        TrieNode(){
            end=false;
        }
    };

    void insert(TrieNode* root, string& str){
        TrieNode* p=root;
        for(char c:str){
            if(!p->next.count(c))
                p->next[c]=new TrieNode();
            p=p->next[c];
        }
        p->end=true;
        p->s=str;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row=board.size(),col=board[0].size();
        set<string> res;
        vector<vector<bool>> used(row,vector<bool>(col,false));
        vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};

        //构建前缀树
        TrieNode* root=new TrieNode();
        for(auto word:words){
            insert(root,word);
        }

        function<void(int,int,TrieNode*)> dfs=[&](int i,int j,TrieNode* t){
            //小剪枝
            if(i>=row||i<0||j>=col||j<0||used[i][j])
                return;

            //大剪枝
            char c=board[i][j];
            if(t->next.count(c)==0)
                return;

            //加入结果集res
            if(t->next[c]->end==true){
                res.insert(t->next[c]->s);
                //此时用的是set，不用去重
            }

            //准备回溯
            used[i][j]=true;

            //四个方向遍历
            for(auto dir:dirs){
                int xi=i+dir.first,xj=j+dir.second;
                dfs(xi,xj,t->next[c]);
            }

            //状态恢复
            used[i][j]=false;
        };

        //遍历
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                dfs(i,j,root);
            }
        }

        vector<string> result;
        result.assign(res.begin(),res.end());
        return result;
    }
};
// @lc code=end

