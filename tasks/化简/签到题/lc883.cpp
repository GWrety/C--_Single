#include<bits/stdc++.h>
//22.4.26
/*
简单
*/
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int x=0,y=0,z=0;
        for(int i=0;i<n;++i){
            int temp1=0,temp2=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0)z++;
                temp1=max(temp1,grid[i][j]);
                temp2=max(temp2,grid[j][i]);
            }
            x+=temp1;
            y+=temp2;
        }
        return x+y+z;
    }
};