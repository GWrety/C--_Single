#include<bits/stdc++.h>
//22.3.10
/*
给你一个整数数组 nums 以及两个整数 lower 和 upper 。求数组中，值位于范围 [lower, upper] （包含 lower 和 upper）之内的 区间和的个数 。
区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。
*/
/*
树状数组的又一道应用  这道又升级了要先提取出前缀和数组，对前缀和数组进行操作
但效果没有归并好，虽然复杂度一样
set是去除重复元素排大小的stl容器
*/
class BIT{
private:
    int n;
    vector<int> tree;
public:
    BIT(int _n):n(_n),tree(_n+1){}
    int lowbit(int a){
        return a&(-a);
    }
    int query(int x){
        int ret=0;
        if(x>=n)x=n;
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
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> Presum{0};
        long long sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            Presum.push_back(sum);
        }
        set<long long> Allnumber;
        for(int i=0;i<Presum.size();++i){
            Allnumber.insert(Presum[i]);
            Allnumber.insert(Presum[i]+lower);
            Allnumber.insert(Presum[i]+upper);
        }
        unordered_map<long long,int> hash;
        int rank=1;
        for(auto item :Allnumber){
            hash[item]=rank;
            ++rank;
        }
        BIT tree(Allnumber.size());
        unsigned int ans=0;
        for(int i=Presum.size()-1;i>=0;--i){
            int left=tree.query(hash[Presum[i]+lower]-1);
            int right=tree.query(hash[Presum[i]+upper]);
            ans+=right-left;
            tree.update(hash[Presum[i]]);
        }
        return ans;
    }
};



class Solution {
public:
    int countRangeSumRecursive(vector<long>& sum, int lower, int upper, int left, int right) {
        if (left == right) {
            return 0;
        } else {
            int mid = (left + right) / 2;
            int n1 = countRangeSumRecursive(sum, lower, upper, left, mid);
            int n2 = countRangeSumRecursive(sum, lower, upper, mid + 1, right);
            int ret = n1 + n2;

            // 首先统计下标对的数量
            int i = left;
            int l = mid + 1;
            int r = mid + 1;
            while (i <= mid) {
                while (l <= right && sum[l] - sum[i] < lower) l++;
                while (r <= right && sum[r] - sum[i] <= upper) r++;
                ret += (r - l);
                i++;
            }

            // 随后合并两个排序数组
            vector<long> sorted(right - left + 1);
            int p1 = left, p2 = mid + 1;
            int p = 0;
            while (p1 <= mid || p2 <= right) {
                if (p1 > mid) {
                    sorted[p++] = sum[p2++];
                } else if (p2 > right) {
                    sorted[p++] = sum[p1++];
                } else {
                    if (sum[p1] < sum[p2]) {
                        sorted[p++] = sum[p1++];
                    } else {
                        sorted[p++] = sum[p2++];
                    }
                }
            }
            for (int i = 0; i < sorted.size(); i++) {
                sum[left + i] = sorted[i];
            }
            return ret;
        }
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long s = 0;
        vector<long> sum{0};
        for(auto& v: nums) {
            s += v;
            sum.push_back(s);
        }
        return countRangeSumRecursive(sum, lower, upper, 0, sum.size() - 1);
    }
};



