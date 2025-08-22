/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //先在首元素上做二分查找，后在该行做二分查找
        int row=matrix.size(),col=matrix[0].size();
        
        int up=0,down=row-1;
        int mid;
        while(up<=down){
            mid=up+(down-up)/2;
            if(matrix[mid][0]==target)
                return true;
            if(up==down)
                mid=up;
            if(matrix[mid][0]<target){
                if(matrix[mid][col-1]<target)
                    up=mid+1;
                else{
                    break;
                }
            }
            else if(matrix[mid][0]>target)
                down=mid-1;
            
        }
        //选定mid即最后的行
        int left=0,right=col-1;
        int line=mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(matrix[line][mid]==target)
                return true;
            else if(matrix[line][mid]<target)
                left=mid+1;
            else{
                right=mid-1;
            }
        }
        return false;

        //还有一种做法是压缩2D至1D，即right=row*col-1，每一次比较的时候matrix[mid / col][mid % col]
    }
};
// @lc code=end

