#include<bits/stdc++.h>
//22.3.6
/*
你和一群强盗准备打劫银行。给你一个下标从 0 开始的整数数组 security ，其中 security[i] 是第 i 天执勤警卫的数量。日子从 0 开始编号。同时给你一个整数 time 。

如果第 i 天满足以下所有条件，我们称它为一个适合打劫银行的日子：

第 i 天前和后都分别至少有 time 天。
第 i 天前连续 time 天警卫数目都是非递增的。
第 i 天后连续 time 天警卫数目都是非递减的。
更正式的，第 i 天是一个合适打劫银行的日子当且仅当：security[i - time] >= security[i - time + 1] >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time].

请你返回一个数组，包含 所有 适合打劫银行的日子（下标从 0 开始）。返回的日子可以 任意 顺序排列。
*/
/*
前后各一遍找满足一个方向条件的，返回两个方向都满足的情况
看题解后：
    可以优化一遍循环，用一个for解决
    还可以记录当前情况，递推公式，在返回时筛>time
*/
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        if(n<=time*2)return {};
        char *left=new char[n];
        char *right=new char[n];
        memset(left,0,n);
        memset(right,0,n);
        if(!time) {
            for(int i=0;i<n;++i){
                left[i]=1;
                right[i]=1;
            }    
        }
        else{
            int lag=1,pre=security[0];
            for(int i=1;i<n;++i){
                if(security[i]<=pre){
                    if(lag>=time){
                        ++left[i];
                    }
                    ++lag;
                }
                else{
                    lag=1;
                }
                pre=security[i];
            }
            lag=1,pre=security[n-1];
            for(int i=n-2;i>=0;--i){
                if(security[i]<=pre){
                    if(lag>=time){
                    ++right[i];
                    }
                    ++lag;
                }
                else{
                    lag=1;
                }
                pre=security[i];
            }
        }
        vector<int> ans;
        for(int i=time;i<n-time;++i){
            if(left[i]&&right[i]) ans.push_back(i);
        }
        return ans;
    }
};