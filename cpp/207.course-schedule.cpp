/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> coursesAvail(numCourses);
        vector<int> inDegree(numCourses,0);

        for(int i=0;i<prerequisites.size();i++){
            inDegree[prerequisites[i][0]]++;
            coursesAvail[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0)
                q.push(i);
        }

        int lessons=0;
        while(!q.empty()){
            lessons++;
            int takecourse=q.front();
            q.pop();
            for(auto& course:coursesAvail[takecourse]){
                inDegree[course]--;
                if(inDegree[course]==0)
                    q.push(course);
            }
        }

        return lessons==numCourses;
    }
};
// @lc code=end

