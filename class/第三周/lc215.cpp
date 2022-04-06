#include<bits/stdc++.h>
//22.3.7
/*
TOPk问题 渴望优化到线性时间
至于为什么时线性时间的推导还没看
*/
class Solution {
public:
    int lag=1;
    int findKthLargest(vector<int>& nums, int k) {
        if(lag){//初始转换
            k=nums.size()-k+1;
            lag=0;
        }
        if(nums.size()<=5){//无法在细分，用直接选择排序
            for(int i=0;i<nums.size();++i){
                for(int j=i+1;j<nums.size();++j){
                    if(nums[j]<nums[i]){
                        swap(nums[j],nums[i]);
                    }
                }
                if(i==k-1) return nums[i];
            }
        }
        vector<int> mid;
        for(int i=0;i<=nums.size()-5;i+=5){//迭代拆分排序
            sort(nums,i,i+4);
            mid.push_back(nums[i+2]);
        }
        std::sort(mid.begin(),mid.end());//利用stl库sort函数排序
        int Mid=mid[mid.size()>>1];
        mid.clear();//这里节省空间用mid当作front进行分组
        vector<int>back;
        int S=0;//相同元素
        int i=0;
        for(;i<=nums.size()-5;i+=5){//划分为两部分
            if(nums[i+2]<Mid){
                for(int j=i;j<i+5;++j){
                    if(j<=i+2)mid.push_back(nums[j]);
                    else if(nums[j]>Mid) back.push_back(nums[j]);
                    else if(nums[j]<Mid)mid.push_back(nums[j]);
                    else ++S;
                }
            }
            else if(nums[i+2]>Mid){
                for(int j=i;j<i+5;++j){
                    if(j>=i+2)back.push_back(nums[j]);
                    else if(nums[j]>Mid) back.push_back(nums[j]);
                    else if(nums[j]<Mid)mid.push_back(nums[j]);
                    else ++S;
                }
            }
            else{
                for(int j=i;j<i+5;++j){
                    if(nums[j]>Mid) back.push_back(nums[j]);
                    else if(nums[j]<Mid)mid.push_back(nums[j]);
                    else ++S;
                }
            }
        }
        while(i<nums.size()){//处理剩下的元素
            if(nums[i]>Mid) back.push_back(nums[i]);
            else if(nums[i]<Mid)mid.push_back(nums[i]);
            else ++S;
            ++i;
        }
        //选择结果
        if(k<=mid.size()){
            return findKthLargest(mid,k);
        }
        else if(k<=mid.size()+S){
            return Mid;
        }
        return findKthLargest(back,k-mid.size()-S);
    }
    void sort(vector<int>& nums,int left,int right){//当数量确定非常小且不总是逆序的时候用插入排序
        for(int i=left+1;i<=right;++i){
            int j=i;
            while(j>left&&nums[j]<nums[j-1]){
                swap(nums[j],nums[j-1]);
                --j;
            }
        }
    }
};