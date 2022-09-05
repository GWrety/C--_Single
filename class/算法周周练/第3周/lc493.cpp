#include<bits/stdc++.h>
//22.3.9
/*
给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。
你需要返回给定数组中的重要翻转对的数量。
*/
/*
用树状数组做会有一个问题，题目要求的关系使确定的，使用的空间不能离散化！
错了，如果要使用树状数组，为了缩减空间必须离散化
对于这种确定关系的题，把元素本身和关系后的值放一起，排序，确保查询范围
只添加原数组就行了
树状数组就是要记住 找符合条件的区间查询，能找到右边的只能顺着找
*/
class BIT
{
private:
    vector<int> tree;
    int n;
public:
    BIT(int _n):n(_n),tree(_n+1){}
    static int lowbit(int x){
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
    void update(int x){
        while(x<=n){
            ++tree[x];
            x+=lowbit(x);
        }
    }
};


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        set<long long> allNumbers;
        for (int x : nums) {
            allNumbers.insert(x);
            allNumbers.insert((long long)x * 2);
        }
        // 利用哈希表进行离散化
        unordered_map<long long, int> values;
        int idx = 0;
        for (long long x : allNumbers) {
            values[x] = ++idx;
        }

        int ret = 0;
        BIT bit(values.size());
        for (int i = 0; i < nums.size(); i++) {
            int left = values[(long long)nums[i] * 2], right = values.size();
            ret += bit.query(right) - bit.query(left);
            bit.update(values[nums[i]]);
        }
        return ret;
    }
};