#include<bits/stdc++.h>
//22.3.20
/*
太长了
*/
/*
小看题解 ：想到了一种解法，先算出0到每个数据服务器的最短路径，此后分别考虑每台服务器的消停时间求解
    过不了啊  只能过到43/50！
    思路上还是没有问题的，过不了的主要原因是n较大时路径矩阵是个稀疏矩阵，建标准矩阵遍历太慢了，改成稀疏的就过了
*/
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size();
        vector<vector<int>> edge(n);//不能n*n
        for (auto & v : edges) {
            edge[v[0]].emplace_back(v[1]);
            edge[v[1]].emplace_back(v[0]);
        }
        vector<int> runtime(n,-1);//路径时间数据
        queue<int> waiting;
        waiting.push(0);
        runtime[0]=0;
        int maxtime=0;
        while(!waiting.empty()){//广度优先遍历求解路径所花费时间
            int temp=waiting.front();
            waiting.pop();
            for(auto & i :edge[temp]){
                if(runtime[i]==-1){
                    runtime[i]=runtime[temp]+1;
                    waiting.push(i);
                    int time=0;//计算时间
                    time+=runtime[i]*2;
                    if(patience[i]<time){
                        int  a=(time-1)%patience[i];
                        time+=runtime[i]*2-a-1;
                    }
                    maxtime=max(time+1,maxtime);
                }
            }
        }
        return maxtime;
    }
};
