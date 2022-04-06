#include<bits/stdc++.h>
//22.2.5
/*
你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。

为了使收益最大化，矿工需要按以下规则来开采黄金：

每当矿工进入一个单元，就会收集该单元格中的所有黄金。
矿工每次可以从当前位置向上下左右四个方向走。
每个单元格只能被开采（进入）一次。
不得开采（进入）黄金数目为 0 的单元格。
矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。
*/
//暴力法+回溯
class Solution {
public:
    int **used;
    int m,n;
    int getMaximumGold(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int answer=0,temp;
        used=new int *[m];
        for(int i=0;i<m;i++){
            used[i]=new int [n];
        }
        clear();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp=GetGold(grid,i,j);
                if(temp>answer){
                    answer=temp;
                }
            }
        }
        return answer;
    }
    int GetGold(vector<vector<int>>&grid,int x,int y){
        if(grid[x][y]==0)return 0;
        int answer=0,temp=0;
        used[x][y]=1;
        if(x-1>=0&&used[x-1][y]==0&&grid[x-1][y]!=0){
            temp=GetGold(grid,x-1,y);
            if(temp>answer){
                answer=temp;
            };
        }
        if(x+1<m&&used[x+1][y]==0&&grid[x+1][y]!=0){
            temp=GetGold(grid,x+1,y);
            if(temp>answer){
                answer=temp;
            };
        }
        if(y-1>=0&&used[x][y-1]==0&&grid[x][y-1]!=0){
            temp=GetGold(grid,x,y-1);
            if(temp>answer){
                answer=temp;
            };
        }
        if(y+1<n&&used[x][y+1]==0&&grid[x][y+1]!=0){
            temp=GetGold(grid,x,y+1);
            if(temp>answer){
                answer=temp;
            };
        }   
        used[x][y]=0;
        return answer+grid[x][y];    
    }
    void clear(){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                used[i][j]=0;
            }
        }
    }
};