#include<bits/stdc++.h>
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n=accounts.size();
        int m=accounts[0].size();
        int ans=0;
        for (size_t i = 0; i < n; i++)
        {   
            int temp=0;
            for (size_t j = 0; j < m; j++)
            {
                temp+=accounts[i][j];
            }
            ans=max(ans,temp);
        }
        return ans;
        
    }
};