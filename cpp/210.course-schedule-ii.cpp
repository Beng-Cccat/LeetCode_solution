/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;

        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto& pre:prerequisites){
            indegree[pre[0]]++;
            adjList[pre[1]].push_back(pre[0]);
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curCourse=q.front();
            q.pop();
            res.push_back(curCourse);

            for(auto& adj:adjList[curCourse]){
                indegree[adj]--;
                if(indegree[adj]==0){
                    q.push(adj);
                }
            }

        }

        if(res.size()==numCourses)
            return res;
        return {};
        //return res.size()==numCourses?res:vector<int>{};
    }
};
// @lc code=end

