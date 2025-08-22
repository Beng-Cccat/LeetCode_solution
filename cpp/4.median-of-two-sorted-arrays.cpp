// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem4.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start

/*思路：多指针*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size(),size2=nums2.size();
        int total=size1+size2;
        int mid1=(total-1)/2;
        int mid2=total/2;       //mid2表示中间那个偏大的数（索引+1）


        int index1=0,index2=0,count=0,pre=0,cur=0;  //count表示cur对应的那个数在排序数列中应该排第几个，数完序号再变化
        double result=0;
        while(count<=mid2){
            pre=cur;
            if(index1<size1&&(index2==size2||nums1[index1]<=nums2[index2])){
                cur=nums1[index1];
                index1++;
            }
            else{
                cur=nums2[index2];
                index2++;
            }
            count++;
        }
        if(total%2==0)
            //这里一定要除以2.0而不是2
            return (pre+cur)/2.0;
        return cur;
    }
};
// @lc code=end

