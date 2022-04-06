#include<bits/stdc++.h>
//22.3.28
/*
给小孩分饼干
饼干有重量，小孩有渴望，求最多
*/
/*
上课贪心引入例题
就是要用最多的饼干
可以给最贪心的小孩先用最大的，也给最不贪心的小孩先用最小的
从逻辑上来说，最好用前一种，多吃点
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0;
        int temp=0;
        int n=g.size();
        for(int i=0;i<s.size();++i){
            if(temp<n&&g[temp]<=s[i]){
                temp++;
                ans++;
            }
        }
        return ans;
    }
};

