/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 */

// @lc code=start
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int len=points.size();
        if(len<3)
            return 0;

        int res=0;
        for(int i=0;i<len;i++){
            unordered_map<long long,int> hmap;
            for(int j=0;j<len;j++){
                if(j==i)continue;
                long long dist=pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2);
                hmap[dist]++;
            }
            for(auto [d,c]:hmap){
                res+=c*(c-1);//有序排列（一个在左一个在右）
            }
        }
        return res;
    }
};
// @lc code=end

