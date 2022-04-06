#include<bits/stdc++.h>
//22.4.1
/*
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
你需要按照以下要求，给这些孩子分发糖果：
每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
*/
/*
贪心希望给最少的糖果
一遍一遍遍历，每人先发一个，
再看谁不符合，多发一个
做法是对的，但效率太低超时
看了一眼题解是排序
可以看已经分配的是不是自己的两边 如果是两边大的+1

这道贪心问题，一开始我的写法一直遍历，每次遍历给每个不满足条件的人一块，这样写虽然最后结果是对的，但最后会超时，	
然后瞄了一眼评论，发现又排序字眼，想了一会，觉得排序之后按顺序，两边每没人就给1，有人因为是顺序查看，所以给作业两边最大的，
同时得识别同样评级的孩子，要单独判断，但效果很差

其实这道题左遍历，右遍历就行了，选出最大的两者
没毛病  想复杂了
*/
//暴力贪心
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int ans=n;
        int pre=0;
        vector<int> temp(n,1);
        while(n!=1&&pre!=ans){
            pre=ans;
            for(int i=0;i<n;++i){
                if(i==0){
                    if(ratings[i]>ratings[i+1]){
                        if(temp[i+1]>=temp[i]){
                            temp[i]++;
                            ans++;
                        }
                    }
                }
                else if(i==n-1){
                    if(ratings[i]>ratings[i-1]){
                        if(temp[i-1]>=temp[i]){
                            temp[i]++;
                            ans++;
                        }
                    }
                }
                else {
                    if(ratings[i]>ratings[i+1]&&temp[i+1]>=temp[i]||ratings[i]>ratings[i-1]&&temp[i]<=temp[i-1]){
                            temp[i]++;
                            ans++;
                        }
                    }
                }
            }
        return ans;
    }
};
//排序贪心，能过 但时间很长
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==1)return 1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<> >p;
        for(int i=0;i<n;++i){
            p.push(make_pair(ratings[i],i));
        }
        vector<int> ans(n,0);
        while(!p.empty()){
            pair<int,int> temp=p.top();
            if(temp.second==0){
                ans[0]=ans[1]+1;
            }
            else if(temp.second==n-1){
                if(ratings[n-1]!=ratings[n-2]){
                    ans[n-1]=ans[n-2]+1;
                }
                else{
                    ans[n-1]=1;
                }
            }
            else{
                if(ratings[temp.second]==ratings[temp.second-1]&&ratings[temp.second]==ratings[temp.second+1]){
                    ans[temp.second]=1;
                }
                else if(ratings[temp.second]==ratings[temp.second-1]){
                    ans[temp.second]=ans[temp.second+1]+1;
                }
                else if(ratings[temp.second]==ratings[temp.second+1]){
                    ans[temp.second]=ans[temp.second-1]+1;
                }
                else{   
                    ans[temp.second]=max(ans[temp.second-1],ans[temp.second+1])+1;
                }
            }
            p.pop();
        }
        int ret=0;
        for(auto &a:ans){
            ret+=a;
        }
        return ret;
    }
};
//两次遍历
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n);
        for (int i = 0; i < n; i++) {
            if (i > 0 && ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            } else {
                left[i] = 1;
            }
        }
        int right = 0, ret = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1 && ratings[i] > ratings[i + 1]) {
                right++;
            } else {
                right = 1;
            }
            ret += max(left[i], right);
        }
        return ret;
    }
};
//常数空间
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ret = 1;
        int inc = 1, dec = 0, pre = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ret += pre;
                inc = pre;//最近递增长度
            } 
            else {
                dec++;//当前递减长度
                if (dec == inc) {/*此外，如果下降长度超过了上升序列，要把下降序列前一个元素也囊入下降序列。
                                    即峰值元素也要按照下降序列规则多发糖了
                                    不然中间分数最高那个小朋友，仅靠递增序列拿的糖，不能维持右侧下降序列的公平了
                                */
                    dec++;
                }
                ret += dec;
                pre = 1;
            }
        }
        return ret;
    }
};




