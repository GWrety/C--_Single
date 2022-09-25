#include <bits/stdc++.h>
using namespace std;

//前三题简单
//Q4并查集不会啊    
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,int> map;
        for (size_t i = 0; i < names.size(); i++)
        {   
            map[heights[i]]=i;
        }
        sort(heights.begin(),heights.end(),greater());
        vector<string> ans;
        for (auto i:heights)
        {
            ans.push_back(names[map[i]]);
        }
        return ans;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int Max=*max_element(nums.begin(),nums.end());
        int ans=1;
        int lag=-1;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i]==Max){
                if(lag!=-1){
                    ans=max(ans,i-lag+1);
                }
                else{
                    lag=i;
                }
            }
            else{
                lag=-1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
                vector<int> ans;
        vector<int> left=vector<int>(nums.size(),0);
        vector<int> right=vector<int>(nums.size(),0);
        int lag=1;
        int lag2=1;
        int preleft=nums[0];
        int preright=nums[nums.size()-1];
        for (size_t i = 1; i < nums.size(); i++)
        {
            if(lag>=k){
                left[i]=1;
            }
            if(nums[i]<=preleft) lag++;
            else{
                lag=1;
            }
            preleft=nums[i];
            if(lag2>=k){
                right[nums.size()-1-i]=1;
            }
             if(nums[nums.size()-1-i]<=preright) lag2++;
            else{
                lag2=1;
            }
            preright=nums[nums.size()-1-i];
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            // cout<<left[i]<<right[i]<<endl;
            if(left[i]&&right[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//123/131
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        vector<vector<int>> edge=vector<vector<int>>(vals.size(),vector<int>(0,0));
        for(auto i:edges){
            edge[i[0]].push_back(i[1]);
            edge[i[1]].push_back(i[0]);
        }
        int ans=vals.size();
        vector<pair<int,int>> map;
        for (size_t i = 0; i < vals.size(); i++)
        {
            for (size_t j = i+1; j < vals.size(); j++)
            {
                if(vals[i]==vals[j]) map.push_back(make_pair(i,j));
            }
        }
        //找到路径 查看节点
        for(auto i:map){
            if(isGood(i.first,i.first,i.second,edge,vals))ans++;
        }
        return ans;
    }
    bool isGood(int pre,int x,int aim,vector<vector<int>>& edge,vector<int>& vals){
        if(x==aim) return true;
        for(auto i:edge[x]){
            if(i!=pre&&vals[i]<=vals[aim]){
                if(isGood(x,i,aim,edge,vals)){
                    return true;
                }
            }
        }
        return false;
    }
};


//Q4并查集
class Solution {
    typedef pair<int, int> pii;

    vector<int> root;
    unordered_map<int, int> mp;

    // 找并查集的根
    int findroot(int x) {
        if (root[x] != x) root[x] = findroot(root[x]);
        return root[x];
    }

public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();

        // 记录树上的边
        vector<vector<int>> e(n);
        for (auto &vec : edges) {
            e[vec[0]].push_back(vec[1]);
            e[vec[1]].push_back(vec[0]);
        }

        // 初始化并查集
        root.resize(n);
        for (int i = 0; i < n; i++) root[i] = i;

        // 将点按点权排序
        vector<pii> vec;
        for (int i = 0; i < n; i++) vec.push_back(pii(vals[i], i));
        sort(vec.begin(), vec.end());

        vector<bool> vis(n);
        long long ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            // 当前枚举的点权有变，清空 mp
            if (vec[i].first != vec[j].first) mp.clear(), j = i;

            // 将 sn 加入树中
            int sn = vec[i].second;
            vis[sn] = true;
            // 一开始没有边和 sn 连接，它所处的连通块只有一个点（也就是它本身）的点权等于 v
            mp[sn] = 1;
            // 枚举从 sn 出发的边
            for (int fn : e[sn]) if (vis[fn]) {
                int x = findroot(sn), y = findroot(fn);
                if (x == y) continue;
                // 答案就是每个被合并的连通块的 mp 之和
                ans += mp[y];
                // 合并两个连通块
                root[x] = y;
                mp[y] += mp[x];
            }
        }
        return ans + n;
    }
};

//Q4 启发式并发 
class Solution {
    typedef pair<int, int> pii;

    vector<int> A;
    long long ans = 0;
    vector<vector<int>> e;

    unordered_map<int, int> dfs(int sn, int fa) {
        // 返回的 map 里一开始只有子树的根
        unordered_map<int, int> ret;
        ret[A[sn]]++;

        for (int fn : e[sn]) if (fn != fa) {
            // 递归调用
            unordered_map<int, int> tmp = dfs(fn, sn);
            // 清除子节点里权值不符合要求的路径
            for (auto it = tmp.begin(); it != tmp.end(); )
                if (it->first < A[sn]) tmp.erase(it++);
                else it++;
            // 启发式合并的关键，每次只能枚举较小的结果
            if (tmp.size() > ret.size()) swap(tmp, ret);
            // 统计路径中深度最小的点为 sn 的好路径数量
            for (auto it = tmp.begin(); it != tmp.end(); it++)
                if (ret.count(it->first)) ans += (it->second) * ret[it->first];
            // 更新返回值
            for (auto it = tmp.begin(); it != tmp.end(); it++) ret[it->first] += it->second;
        }

        return ret;
    }

public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        A = vals;
        e.resize(n);
        for (auto &vec : edges) {
            e[vec[0]].push_back(vec[1]);
            e[vec[1]].push_back(vec[0]);
        }

        dfs(0, 0);
        return ans + n;
    }
};


int main()
{
    
    system("pause");
    return 0;
}
