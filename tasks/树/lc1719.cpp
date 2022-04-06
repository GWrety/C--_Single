#include <bits/stdc++.h>
//22.2.16
/*
给你一个数组 pairs ，其中 pairs[i] = [xi, yi] ，并且满足：
pairs 中没有重复元素
xi < yi
令 ways 为满足下面条件的有根树的方案数：
树所包含的所有节点值都在 pairs 中。
一个数对 [xi, yi] 出现在 pairs 中 当且仅当 xi 是 yi 的祖先或者 yi 是 xi 的祖先。
注意：构造出来的树不一定是二叉树。
两棵树被视为不同的方案当存在至少一个节点在两棵树中有不同的父节点。
请你返回：
如果 ways == 0 ，返回 0 。
如果 ways == 1 ，返回 1 。
如果 ways > 1 ，返回 2 。
一棵 有根树 指的是只有一个根节点的树，所有边都是从根往外的方向。
我们称从根到一个节点路径上的任意一个节点（除去节点本身）都是该节点的 祖先 。根节点没有祖先。
*/
/*
    就是先找到规律，依据度数确定上下关系，再通过样例对一些特殊的情况加以纠正
*/
//这道题解法有点意思，日后品味
using namespace std;
class Solution {
public:
    static bool cmp(const pair<int,int> x,const pair<int,int> y)
    {
        return x.second>y.second;
        /* vector<pair<int,int>> ratio;
        int n=0;
        for(auto a=Hashmap.begin();a!=Hashmap.end();a++){
            pair<int,int> temp;
            temp.first=a->first;
            temp.second=a->second;
            ratio.push_back(temp);
            n++;
        }
        sort(ratio.begin(),ratio.end(),cmp);
        if(sonmap[ratio[0].first]+1<n)return 0; */
    }
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int ,int> Hashmap;
        for(int i=0;i<pairs.size();i++){
            Hashmap[pairs[i][0]]++;
            Hashmap[pairs[i][1]]++;
        }
        unordered_map<int,int> fathermap;
        unordered_map<int,int> sonmap;
        unordered_map<int,int> friendmap;
        int n=Hashmap.size();
        for(int i=0;i<pairs.size();i++){
            if(Hashmap[pairs[i][0]]>Hashmap[pairs[i][1]]){
                sonmap[pairs[i][0]]++;
                fathermap[pairs[i][1]]++;
            }
            else if(Hashmap[pairs[i][0]]==Hashmap[pairs[i][1]]){
                friendmap[pairs[i][0]]++;
                friendmap[pairs[i][1]]++;
            }
            else{
                sonmap[pairs[i][1]]++;
                fathermap[pairs[i][0]]++;
            }
        }
        int lag1=0;
        int lag2=0;
        unordered_map<int,int> test;
        for(int i=0;i<pairs.size();i++){
            if(friendmap[pairs[i][0]]>=1||friendmap[pairs[i][1]]>=1){
                lag1++;
            }
            if(Hashmap[pairs[i][0]]>Hashmap[pairs[i][1]]){
                lag2=1;
                if(fathermap[pairs[i][0]]+friendmap[pairs[i][0]]>fathermap[pairs[i][1]]-1){
                    return 0;
                }
                else if(fathermap[pairs[i][0]]+friendmap[pairs[i][0]]==fathermap[pairs[i][1]]-1){
                    test[pairs[i][1]]++;
                }
            }
            else if(Hashmap[pairs[i][0]]<Hashmap[pairs[i][1]]){
                lag2=1;
                if(fathermap[pairs[i][1]]+friendmap[pairs[i][1]]>fathermap[pairs[i][0]]-1){
                    return 0;
                }
                else if(fathermap[pairs[i][1]]+friendmap[pairs[i][1]]==fathermap[pairs[i][0]]-1){
                    test[pairs[i][0]]++;
                }
            }
        }
        int max=0;
        int lag3=0;
        for(auto a=Hashmap.begin();a!=Hashmap.end();a++){
            if(max<a->second){
                max=a->second;
            }
        }
        for(auto a=Hashmap.begin();a!=Hashmap.end();a++){
            if(max==a->second){
                lag3++;
            }
        }
        if(max+1!=n)return 0;
        if(lag2&&lag3==1&&test.size()!=n-1)return 0;
        if(lag1)return 2;
        return 1;
    }
};
