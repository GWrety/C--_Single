#include<bits/stdc++.h>
//22.2.13
/*
    给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。
字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。
*/
/*常规题目 哈希统计，分析
    但代码比较漂亮
*/
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> s_map;
        for(int i=0;i<text.size();i++){
            s_map[text[i]]++;
        }
        string aim="balloon";
        int answer=INT_MAX;
        for(int i=0;i<aim.size();i++){
            if(!s_map[aim[i]]) return 0;
            else if(aim[i]!='l'&&aim[i]!='o'){
                if(answer>s_map[aim[i]]){
                    answer=s_map[aim[i]];
                }
            }
            else{
                if(answer>s_map[aim[i]]/2){
                    answer=s_map[aim[i]]/2;
                }
            }
        }
        return answer;
    }   
};