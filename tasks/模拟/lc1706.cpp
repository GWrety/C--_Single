#include<bits/stdc++.h>
//22.2.24
/*
用一个大小为 m x n 的二维网格 grid 表示一个箱子。你有 n 颗球。箱子的顶部和底部都是开着的。

箱子中的每个单元格都有一个对角线挡板，跨过单元格的两个角，可以将球导向左侧或者右侧。

将球导向右侧的挡板跨过左上角和右下角，在网格中用 1 表示。
将球导向左侧的挡板跨过右上角和左下角，在网格中用 -1 表示。
在箱子每一列的顶端各放一颗球。每颗球都可能卡在箱子里或从底部掉出来。如果球恰好卡在两块挡板之间的 "V" 形图案，或者被一块挡导向到箱子的任意一侧边上，就会卡住。

返回一个大小为 n 的数组 answer ，其中 answer[i] 是球放在顶部的第 i 列后从底部掉出来的那一列对应的下标，如果球卡在盒子里，则返回 -1 。
*/
/*
    模拟一下球的运行轨迹即可，被vector的行和列区分纠缠了一会
    识别好 撞墙 和能走，其余都是卡住
*/
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid[0].size();
        int n=grid.size();
        vector<int> ans(m,-1);
        for(int i=0;i<m;i++){
            int pos_x=0,pos_y=i;
            int is_change=1;
            while(is_change){
                is_change=0;
                if(pos_x>=n){
                    ans[i]=pos_y;
                }
                else if(pos_y==0&&grid[pos_x][pos_y]==-1){
                    ans[i]=-1;
                }
                else if(pos_y==m-1&&grid[pos_x][pos_y]==1){
                    ans[i]=-1;
                }
                else if(grid[pos_x][pos_y]==1&&grid[pos_x][pos_y+1]==1){
                    pos_x++;pos_y++;is_change=1;
                }
                else if(grid[pos_x][pos_y]==-1&&grid[pos_x][pos_y-1]==-1){
                    pos_x++;pos_y--;is_change=1;
                }
                else{
                    ans[i]=-1;
                }
            }
        }
        return ans;
    }
};