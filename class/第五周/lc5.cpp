#include<bits/stdc++.h>
//22.3.21
/*
给你一个字符串 s，找到 s 中最长的回文子串。
*/
/*
dp区间 从下向上填
在查看题解后，发现有一种中心扩展法，就是以每个字符开始向周围扩展，直到不能扩展为止，
这种解法是比较直观的，虽然很暴力，但效果也很好。
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int left=0,right=0;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i){
            dp[i][i]=1;//单个单词是一个回文子串
        }
        for(int i=n-1;i>=0;--i){
            for(int j=i+1;j<n;++j){
                if(s[i]==s[j]){
                    if(j-i==1){
                        dp[i][j]=1;//边界问题
                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                if(dp[i][j]){//记录最长位置
                    if(j-i>right-left){
                        right=j;
                        left=i;
                    }
                }
            }
        }
        string ans=s.substr(left,right-left+1);
        return  ans;
    }
};