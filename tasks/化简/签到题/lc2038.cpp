#include<bits/stdc++.h>
//22.3.23
/*
总共有 n 个颜色片段排成一列，每个颜色片段要么是 'A' 要么是 'B' 。给你一个长度为 n 的字符串 colors ，
其中 colors[i] 表示第 i 个颜色片段的颜色。
Alice 和 Bob 在玩一个游戏，他们 轮流 从这个字符串中删除颜色。Alice 先手 。
如果一个颜色片段为 'A' 且 相邻两个颜色 都是颜色 'A' ，那么 Alice 可以删除该颜色片段。Alice 不可以 删除任何颜色 'B' 片段。
如果一个颜色片段为 'B' 且 相邻两个颜色 都是颜色 'B' ，那么 Bob 可以删除该颜色片段。Bob 不可以 删除任何颜色 'A' 片段。
Alice 和 Bob 不能 从字符串两端删除颜色片段。
如果其中一人无法继续操作，则该玩家 输 掉游戏且另一玩家 获胜 。
假设 Alice 和 Bob 都采用最优策略，如果 Alice 获胜，请返回 true，否则 Bob 获胜，返回 false。
*/
/*
这道题一眼感觉比模拟就行了，
每次能操作就操作   不能就输了
应该能优化  是否可以遍历一次统计每个人的机会 机会多的WIn
有一个疑问 最优策略会影响吗?  因该不会 边界牢不可破
秒杀 
*/
class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0,bob=0;
        int n=colors.size();
        for(int i=1;i<n-1;++i){
            if(colors[i]=='A'&&colors[i-1]=='A'&&colors[i+1]=='A'){
                alice++;
            }
            else if(colors[i]=='B'&&colors[i-1]=='B'&&colors[i+1]=='B'){
                bob++;
            }
        }   
        return alice>bob? 1:0;
    }
};
