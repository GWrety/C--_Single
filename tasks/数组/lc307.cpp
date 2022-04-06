#include<bits/stdc++.h>
//22.4.4
/*
给你一个数组 nums ，请你完成两类查询。
其中一类查询要求 更新 数组 nums 下标对应的值
另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，其中 left <= right
实现 NumArray 类：
NumArray(int[] nums) 用整数数组 nums 初始化对象
void update(int index, int val) 将 nums[index] 的值 更新 为 val
int sumRange(int left, int right) 返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的
和 （即，nums[left] + nums[left + 1], ..., nums[right]）
*/
/*树状数组单点更新，区间查询
树状数组模板 easy
*/
class BIT{
public:
    vector<int>tree;
    int n;
    BIT(int _n):n(_n),tree(_n+1){};
    void update(int x,int t){
        while(x<=n){
            tree[x]+=t;
            x+=lowbit(x);
        }
    }   
    int lowbit(int x){
        return x&(-x);
    }
    int query(int x){
        int ret=0;
        while(x){
            ret+=tree[x];
            x-=lowbit(x);
        }
        return ret;
    }
};
class NumArray {
private:
    int n;
    BIT x;
    vector<int> t;
public:
    NumArray(vector<int>& nums):n(nums.size()),x(n),t(nums){
        for(int i=0;i<n;++i){
            x.update(i+1,nums[i]);
        }
    }
    void update(int index, int val) {
        x.update(index+1,val-t[index]);
        t[index]=val;
    }
    int sumRange(int left, int right) {
        return x.query(right+1)-x.query(left);
    }
};