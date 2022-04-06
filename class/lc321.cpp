#include<bits/stdc++.h>
//22.4.1
/*
给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m + n) 
个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。
求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。
*/
/*
贪心准则：总希望最大的数子放到最高位上
两个问题：
    1.最高数字选了之后，剩下的数字不够了
    2.两个相等的数字 选那个都行？
解决不了 放弃
其实写到最后能意识到必须使用单调栈
*/
//失败版本
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k,-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<>> p;
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<>> v;
        int m=nums1.size();
        int n=nums2.size();
        for(int i=0;i<m;i++){
            p.push(make_pair(nums1[i],i));
        }
        for(int i=0;i<n;i++){
            v.push(make_pair(nums2[i],i));
        }
        int m_now=-1,n_now=-1;
        for(int i=0;i<k;){
            if(ans[i]!=-1) {
                i++;continue;
            }
            if(!p.empty()&&v.empty()||p.top().first>=v.top().first){
                pair<int,int> temp=p.top();
                if(temp.second>m_now){
                    int st=max(i,k-(m-temp.second)-(int)v.size());
                    ans[st]=temp.first;
                    m_now=temp.second;
                }
                p.pop();
            }
            else{
                pair<int,int> temp=v.top();
                if(temp.second>n_now){
                    int st=max(i,k-(n-temp.second)-(int)p.size());
                    ans[st]=temp.first;
                    n_now=temp.second;
                }
                v.pop();
            }
        }
        return ans;
    }
};
//题解 单调栈
class Solution {
public: 
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> maxSubsequence(k, 0);
        int start = max(0, k - n), end = min(k, m);
        for (int i = start; i <= end; i++) {
            vector<int> subsequence1(MaxSubsequence(nums1, i));
            vector<int> subsequence2(MaxSubsequence(nums2, k - i));
            vector<int> curMaxSubsequence(merge(subsequence1, subsequence2));
            if (compare(curMaxSubsequence, 0, maxSubsequence, 0) > 0) {
                maxSubsequence.swap(curMaxSubsequence);
            }
        }
        return maxSubsequence;
    }
    vector<int> MaxSubsequence(vector<int>& nums, int k) {//求最大k个单调序列
        int length = nums.size();
        vector<int> stack(k, 0);//单调栈用数组实现
        int top = -1;
        int remain = length - k;
        for (int i = 0; i < length; i++) {
            int num = nums[i];//待选数
            while (top >= 0 && stack[top] < num && remain > 0) {//带选数大且有剩余
                top--;
                remain--;
            }
            if (top < k - 1) {
                stack[++top] = num;//放到栈顶
            } 
            else {//没空 扔掉
                remain--;
            }
        }
        return stack;
    }

    vector<int> merge(vector<int>& subsequence1, vector<int>& subsequence2) {
        int x = subsequence1.size(), y = subsequence2.size();
        if (x == 0) {
            return subsequence2;
        }
        if (y == 0) {
            return subsequence1;
        }
        int mergeLength = x + y;
        vector<int> merged(mergeLength);
        int index1 = 0, index2 = 0;
        for (int i = 0; i < mergeLength; i++) {
            if (compare(subsequence1, index1, subsequence2, index2) > 0) {
                merged[i] = subsequence1[index1++];
            } else {
                merged[i] = subsequence2[index2++];
            }
        }
        return merged;
    }

    int compare(vector<int>& subsequence1, int index1, vector<int>& subsequence2, int index2) {
        int x = subsequence1.size(), y = subsequence2.size();
        while (index1 < x && index2 < y) {
            int difference = subsequence1[index1] - subsequence2[index2];
            if (difference != 0) {
                return difference;
            }
            index1++;
            index2++;
        }
        return (x - index1) - (y - index2);
    }
};