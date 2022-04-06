#include<bits/stdc++.h>
//22.3.29
/*
给定两个大小相等的数组 A 和 B，A 相对于 B 的优势可以用满足 A[i] > B[i] 的索引 i 的数目来描述。
返回 A 的任意排列，使其相对于 B 的优势最大化。
*/
/*
课上例题，田忌赛马
还和田忌赛马不太一样，齐威王的马是有顺序的 把最后一个抗过来直接比就行，不会浪费
这个顺序不一样，会浪费
贪心准则：尽可能让每一匹马，都有用
高的都打不过就派最低的
能打过希望花费最小的代价
常规贪心超时 复杂度为n2
为了缩减时间规模，必须把无序的nums2也进行排序，优化寻找这个阶段
聪明的齐威王很难搞 硬实力才是王道
*/
//常规贪心超时
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> pre=nums1;
        sort(pre.begin(),pre.end());
        int n=nums1.size();
        char *used=new char[n];
        memset(used,0,n);
        int right=n-1;
        int left=0;
        for(int i=0;i<n;++i){
            if(nums2[i]<pre[right]){
                int temp=right;
                while(temp>=left&&pre[temp]>nums2[i]){temp--;}
                temp++;
                while(used[temp]==1)temp++;
                nums1[i]=pre[temp];
                used[temp]=1;
                while(right>=0&&used[right]==1)right--;
                while(left<n&&used[left]==1)left++;
            }
            else{
                nums1[i]=pre[left];
                used[left]=1;
                left++;
                while(left<n&&used[left]==1)left++;
            }
        }
        return nums1;
    }
};
//把nums2也排序
class Solution 
{
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B)//方法2
    {
        vector<pair<int,int>>v;
        vector<int>ans(A.size(),-1);

        for(int i=0;i<B.size();i++)
            v.push_back(make_pair(B[i],i));//pair排序默认按第一关键字升序,若第一关键字相同再按第二关键字

        sort(A.begin(),A.end());
        sort(v.begin(),v.end());

        int Al = 0,Ar = A.size()-1,Br = v.size()-1;
        while(Br >= 0)
        {
            if(A[Ar] > v[Br].first)//Amax>Bmax  Amax去对位Bmax
            {
                ans[v[Br].second] = A[Ar];
                Ar--;
            }
            else//Amax<Bmax   Amin去对位Bmax
            {
                ans[v[Br].second] = A[Al];
                Al++;
            }
            Br--;
        }
        return ans;
    }
};

