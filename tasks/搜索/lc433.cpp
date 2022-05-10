#include<bits/stdc++.h>
//22.5.9
/*
基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。

假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。

例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。

给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。

注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。

和单词接龙的题目是一样的，基于已有的list去暴力搜索
*/
class Solution {
int ans=-1;

public:
    int minMutation(string start, string end, vector<string>& bank) {
        if(start==end)return 0;
        vector<string>::iterator t=find(bank.begin(),bank.end(),end);
        if(t==bank.end())return -1;
        set<string> route;
        route.insert(start);
        for(auto i:bank){
            if(islike(i,start)){
                route.insert(i);
                func(i,end,bank,route);
                route.erase(i);
            }
        }
        return ans;
    }

    void func(string start,string end,vector<string>& bank,set<string> route){
        if(start==end){
            int n=route.size();
            n--;
            if(ans=-1||n<ans){
                ans=n;
            }
            return;
        }
        for(auto i:bank){
            if(islike(i,start)&&route.find(i)==route.end()){
                route.insert(i);
                func(i,end,bank,route);
                route.erase(i);
            }
        }
    }
    bool islike(string a,string b){
        int l=0,lag=0;
        for(auto i:a){
            if(b[l]!=i){
                if(!lag)lag=1;
                else return false;
            }
            l++;
        }
        return lag;
    }
};