#include<bits/stdc++.h>
//22.3.26
/*
你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。
比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 ops，其中 ops[i] 是你需要记录的第 i 项操作，ops 遵循下述规则：
整数 x - 表示本回合新获得分数 x
"+" - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。
"D" - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。
"C" - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。
请你返回记录中所有得分的总和。
*/
/*
签到题
2021.8.28 数据结构中用栈做过
今天用vector又过了
*/
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> ans;
        int now=0;
        for(int i=0;i<ops.size();++i){
            if(ops[i]=="+") {
                ans.push_back(ans[now-1]+ans[now-2]);
                now++;
            }
            else if(ops[i]=="C"){
                ans.pop_back();
                now--;
            }
            else if(ops[i]=="D"){
                ans.push_back(ans[now-1]*2);
                now++;
            }
            else{
                ans.push_back(stoi(ops[i]));
                now++;
            }
        }
        int ret=0;
        for(auto i:ans){
            ret+=i;
        }
        return ret;
    }
};
