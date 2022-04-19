#include<bits/stdc++.h>
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        vector<int> ans(n,n);
        int temp=n;
        for(int i=0;i<n;++i){
            if(s[i]==c){
                temp=0;
                ans[i]=0;
            }
            else{
                if(temp<n)temp++;
                ans[i]=temp;
            }
        }
        temp=n;
        for(int i=n-1;i>=0;--i){
            if(s[i]==c)temp=0;
            else{
                if(temp<n)temp++;
                ans[i]=min(ans[i],temp);
            }
        }
        return ans;
    }
};