#include<bits/stdc++.h>
//8皇后
class Solution {
    vector<vector<string>> ans;
    vector<int> temp_sit;
public:
    vector<vector<string>> solveNQueens(int n) {
        temp_sit.resize(n);
        function(0,n);
        
        return ans;
    }
    void function(int x,int  n){
        if(x==n){
            pushans(n);
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
    void pushans(int n){ 
        vector<string> temp(n,"");
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(temp_sit[i]!=j)temp[j].push_back('.');
                else{
                    temp[j].push_back('Q');
                }
            }
        }
        ans.push_back(temp);
    }
};