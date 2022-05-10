#include<bits/stdc++.h>
/*
统计最小高度数
理论上应该都得遍历一遍
可以在遍历过大时剪枝
65/70
还需要剪枝可以先遍历分支大的节点
效果没有差别
应该是方法的问题
朴素暴力过不了
*/
//error朴素暴力
class Solution {
    int length=INT_MAX;
    vector<int> ans;
    int aim;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>  role(n,vector<int>(0));
        for(int i=0;i<n-1;++i){
            role[edges[i][0]].push_back(edges[i][1]);
            role[edges[i][1]].push_back(edges[i][0]);
        }
        vector<pair<int,int>>wit;
        for(int i=0;i<n;++i){
            wit.push_back(make_pair(role[i].size(),i));
        }
        sort(wit.begin(),wit.end());
        vector<vector<int>> temp;
        vector<int> used(n,0);
        queue<int> now;
        int step;
        for(int i=n-1;i>=0;--i){
            int m=wit[i].second;
            temp=role;
            step=0;
            for(auto &i:used){
                i=0;
            }
            aim=m;
            while(!now.empty()){
                now.pop();
            }
            now.push(m);
            BFS(temp,now,used,step);
        }
        return ans;
    }   
    void BFS(vector<vector<int>>& temp,queue<int> now,vector<int> &used,int& step){
        if(step>length) return;         
        queue<int> q;
        while(!now.empty()){
            int a=now.front();
            now.pop();
            for(auto &i:temp[a]){
                if(!used[i]){
                    q.push(i);
                }
            }
            used[a]=1;
        }
        if(q.empty()){
            if(step<length){
                length=step;
                ans.clear();
                ans.push_back(aim);
            }
            else if(step==length){
                ans.push_back(aim);
            }
            return;
        }
        step++;
        return BFS(temp,q,used,step);
    }
};
//换根Dp
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> h(n);
        for(auto &v : edges) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        function<void(int, int)> dfs = [&](int x, int fa) {
            h[x] = 1;
            for(auto &y : g[x]) {
                if(y == fa) continue;
                dfs(y, x);
                h[x] = max(h[x], h[y] + 1);
            }
            
        };
        function<void(int, int, int)> dfs2 = [&](int x, int fa, int high) {
            h[x] = max(h[x], high + 1);
            int fi = high + 1, se = 0;
            for(auto &y : g[x]) {
                if(y == fa) continue;
                if(h[y] + 1 >= fi) se = fi, fi = h[y] + 1;
                else if(h[y] + 1 >= se) se = h[y] + 1;
            }
            for(auto &y : g[x]) {
                if(y == fa) continue;
                if(h[y] + 1 == fi) dfs2(y, x, se);
                else dfs2(y, x, fi);
            }
        };
        dfs(0, -1);
        dfs2(0, -1, 0);
        int mh = *min_element(h.begin(), h.end());
        vector<int> rs;
        for(int i = 0; i < n; i++) if(h[i] == mh) rs.push_back(i);
        return rs;
    }
};
//拓扑排序
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<int> degree(n);
        vector<vector<int>> adj(n);
        for (auto & edge : edges){
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> qu;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                qu.emplace(i);
            }
        }
        int remainNodes = n;
        while (remainNodes > 2) {
            int sz = qu.size();
            remainNodes -= sz;
            for (int i = 0; i < sz; i++) {
                int curr = qu.front();
                qu.pop();
                for (auto & v : adj[curr]) {
                    if (--degree[v] == 1) {
                        qu.emplace(v);
                    }
                }
            }
        }
        while (!qu.empty()) {
            ans.emplace_back(qu.front());
            qu.pop();
        }
        return ans;
    }
};


