#include<bits/stdc++.h>
//22.3.1
/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。
*/
/*
首先可以确定这道题的思路是有迹可循的，题目要求了log（m+n）的做法就代表了一定是二分的做法
但对于如何二分，需要深入思考一下
难点就在于判断二分条件，
首先 我们选择的方法是抛弃前（m+n）个数字，
对于二分后这一半的数字，只有在结果肯定不出现在他们中时才能抛弃，
得保证 上下俩部分和小于要抛弃的目标数字，就可以放心扔掉小的那一半，向右逼近
如果他自己本身都大于aim，一定影响结果 就要把自己向左逼近
在上述俩者之间时，不能盲目移动，要先开偏大的那部分内核，在把内核逼近到1个单位时，这样移动才是安全的
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();//获得条件
        int aim=(m+n)/2;//中位数位置
        double ans=0;

        int left1=0,left2=0,right1=m-1,right2=n-1;//两个二分条件
        int mid1,mid2;

        if(aim==0){
            if(m+n==0)ans=0;//防止空
            if(m) ans=nums1[0];
            else ans=nums2[0];
            return ans;
        }
        int lag=0;//奇偶标记
        if(!((m+n)%2)) {
            lag=1;//偶为1
        }
        else{
            ++aim;
        }
        --aim;//aim为目标减去的数字数

        while(1){
            if(aim==0){//如果不需要删减数字
                if(m-1<left1){
                    ans=nums2[left2];
                    if(lag){
                        ans+=nums2[left2+1];
                    }
                }
                else if(n-1<left2){
                    ans=nums1[left1];
                    if(lag){
                        ans+=nums1[left1+1];
                    }
                }
                else if(nums1[left1]<nums2[left2]){
                    ans=nums1[left1];
                    if(lag){
                        if(left1==m-1||nums2[left2]<nums1[left1+1])ans+=nums2[left2];
                        else ans+=nums1[left1+1];
                    }
                }
                else{
                    ans=nums2[left2];
                    if(lag){
                        if(left2==n-1||nums1[left1]<nums2[left2+1])ans+=nums1[left1];
                        else ans+=nums2[left2+1];
                    }
                }
                break;
            }
            if(left1>right1||left2>right2){//一个序列空了
                int left,right,mid;//降级为一个二分
                int tag;
                if(left1>right1){//赋值
                    left=left2;right=right2;tag=2;
                }
                else{
                    left=left1;right=right1;tag=1;
                }
                while(1){//一个二分寻找
                    mid=left+(right-left)/2;
                    if(mid-left>aim){
                        right=mid;
                    }
                    else if(mid-left<aim){
                        aim-=mid-left;
                        left=mid;
                    }
                    else if(mid-left==aim){  
                        if(tag==2){
                            ans=nums2[mid];
                            if(lag){//偶数情况下可能被隐藏
                                ans+=nums2[mid+1];                             
                            }
                        }
                        else{
                            ans=nums1[mid];
                            if(lag){//偶数情况下可能被隐藏
                                ans+=nums1[mid+1];                              
                            }
                        }
                        break;
                    }
                }
                break;
            }
            //两个数组夹逼
            mid1=left1+(right1-left1)/2;
            mid2=left2+(right2-left2)/2;
            //要点在这里，判断二分条件
            if(nums1[mid1]>nums2[mid2]){
                if((mid2-left2+1)+(mid1-left1)<=aim){
                    aim-=(mid2-left2+1);
                    left2=mid2+1;
                }
                else if((mid2-left2+1)>aim){
                    right2=mid2;
                }
                else {
                    if(mid1!=right1){
                        right1=mid1;
                    }
                    else{
                        aim-=mid2-left2+1;
                        left2=mid2+1;
                        
                    }
                }
            }
            else if(nums1[mid1]<nums2[mid2]){
                if((mid1-left1+1)+(mid2-left2)<=aim){
                    aim-=(mid1-left1+1);
                    left1=mid1+1;
                }
                else if((mid1-left1+1)>aim){
                    right1=mid1;
                }
                else {
                    if(mid2!=right2){
                        right2=mid2;
                    }
                    else{
                        aim-=mid1-left1+1;
                        left1=mid1+1;
                        
                    }
                }
            }
            else{//等于的情况（甚至 num1和num2相等）  左右拉扯 尽量不影响结果
                if(nums1[left1]<nums2[left2]) {
                    ++left1;
                    --aim;    
                }
                else if(nums1[left1]>nums2[left2]){
                    ++left2;
                    --aim;
                }
                else if(left1<right1&&nums1[left1+1]==nums2[left2]){
                    ++left1;
                    --aim;   
                }
                else if(left2<right2&&nums1[left2+1]==nums2[left1]){
                    ++left2;
                    --aim;
                }
                else{
                    ++left1;
                    --aim; 
                }
            }
        }
        if(lag) ans/=2.0;;
        return ans;
    }
};

