#include<bits/stdc++.h>
/*
平滑单元格，每个遍历O（M*N）可以做
应该没什么简便方法
*/
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                ans[i][j]=function(i,j,img,m,n);
            }
        }
        return ans;
    }
    int function(int i,int j,vector<vector<int>>& img,int m,int n){
        int ret=img[i][j];
        int lag=1;
        if(i-1>=0&&j-1>=0){
            ret+=img[i-1][j-1];
            lag++;
        }
        if(i-1>=0){
            ret+=img[i-1][j];lag++;
        }
        if(i-1>=0&&j+1<n){
            ret+=img[i-1][j+1];lag++;
        }
        if(j+1<n){
            ret+=img[i][j+1];lag++;
        }
        if(j-1>=0){
            ret+=img[i][j-1];lag++;
        }
        if(i+1<m&&j+1<n){
            ret+=img[i+1][j+1];lag++;
        }
        if(i+1<m){
            ret+=img[i+1][j];lag++;
        }
        if(i+1<m&&j-1>=0){
            ret+=img[i+1][j-1];lag++;
        }
        return ret/lag;
    }
};

