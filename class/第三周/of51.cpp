#include<bits/stdc++.h>
//22.3.8
/*
求解一个数组中出现了多少逆序对
*/
/*
逆序对问题，上课讲过  归并最好用n*logN
对于归并排序 最好还是传个引用当temp比较好
还有一种解法 离散化树状数组  
离散化的意思是优化空间，不必耗费过多的无用空间 
lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素。
也就是说，使用该函数在指定范围内查找某个目标值时，最终查找到的不一定是和目标值相等的元素，还可能是比目标值大的元素
*/
//归并排序  效果一般奥
class Solution {
public:
    int ans=0;
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        function(nums,temp,0,nums.size()-1);
        return ans;
    }
    void function(vector<int>&nums,vector<int>&temp,int left,int right){
        if(left>=right)return;
        int mid=left+(right-left)/2;
        function(nums,temp,left,mid);
        function(nums,temp,mid+1,right);
        int prt1=left,prt2=mid+1;
        int i=0;
        //边比边排序
        while(prt1<=mid&&prt2<=right){
            if(nums[prt1]>nums[prt2]){
                temp[i]=nums[prt2];
                ++i;
                ++prt2;
            }
            else {
                ans+=prt2-mid-1;
                temp[i]=nums[prt1];
                ++prt1;
                ++i;
            }
        }
        //剩下的数
        while(prt1<=mid){
            ans+=right-mid;
            temp[i]=nums[prt1];
            ++prt1;
            ++i;
        }
        while(prt2<=right){
            temp[i]=nums[prt2];
            ++prt2;
            ++i;
        }
        //拷贝排序好的值
        for(int i=left;i<=right;++i){
            nums[i]=temp[i-left];
        }
    }
};

//树状数组
class BIT {
private:
    vector<int> tree;
    int n;
public:
    BIT(int _n): n(_n), tree(_n + 1) {}
    static int lowbit(int x) {
        return x & (-x);
    }
    int query(int x) {
        int ret = 0;
        while (x) {
            ret += tree[x];
            x -= lowbit(x);
        }
        return ret;
    }
    void update(int x) {
        while (x <= n) {
            ++tree[x];
            x += lowbit(x);
        }
    }
};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp = nums;
        // 离散化
        sort(tmp.begin(), tmp.end());
        for (int& num: nums) {
            num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;//只有vector才有
        }
        // 树状数组统计逆序对
        BIT bit(n);
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans += bit.query(nums[i] - 1);
            bit.update(nums[i]);
        }
        return ans;
    }
};






