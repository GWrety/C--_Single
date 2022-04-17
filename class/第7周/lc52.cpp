#include<bits/stdc++.h>
//8皇后
class Solution {
    int ans=0;
    vector<int> temp_sit;
public:
    int totalNQueens(int n) {
    temp_sit.resize(n);
        function(0,n);
        
        return ans;
    }
    void function(int x,int  n){
        if(x==n){
            ans++;
            return;
        }
        for(int i=0;i<n;++i){
            temp_sit[x]=i;
            if(issafe(x)) function(x+1,n);
        }
    }
    bool issafe(int x){
        for(int i=0;i<x;++i){
            if(temp_sit[x]==temp_sit[i]||abs(temp_sit[x]-temp_sit[i])==abs(x-i)){
                return 0;
            }
        }
        return 1;
    }
};