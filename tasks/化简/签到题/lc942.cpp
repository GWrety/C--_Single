#include<bits/stdc++.h>
//22.5.9
/*
由范围 [0,n] 内所有整数组成的 n + 1 个整数的排列序列可以表示为长度为 n 的字符串 s ，其中:

如果 perm[i] < perm[i + 1] ，那么 s[i] == 'I' 
如果 perm[i] > perm[i + 1] ，那么 s[i] == 'D' 
给定一个字符串 s ，重构排列 perm 并返回它。如果有多个有效排列perm，则返回其中 任何一个 。


因该是贪心如果是I放最小的
如果是D放最大的
*/
class Solution {
public:
    vector<int> diStringMatch(string s) {
        deque<int> wit;
        vector<int> ans;
        int n=s.size();
        for(int i=0;i<n;++i)wit.push_back(i);
        for(auto i:s){
            if(i=='I'){
                ans.push_back(wit.front());
                wit.pop_front();
            }
            else{
                ans.push_back(wit.back());
                wit.pop_back();
            }
        }
        ans.push_back(wit.front());
        return ans;
    }
};