#include<bits/stdc++.h>
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int ret=1;
        int ans=0;
        for(auto i :s){
            if(widths[i-'a']+ans>100){
                ret++;
                ans=widths[i-'a'];
            }
            else{
                ans+=widths[i-'a'];
            }
        }
        return {ret,ans};
    }
};