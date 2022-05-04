#include<bits/stdc++.h>
//22.5.3
/*
传统的排序问题，可用先把字母的放到一个容器中，
在把数字的放到一个容器中 数字的顺序放
字母重写一下排序规则吧
重复习了下优先队列
记住了一个找第一个空格的函数
*/

class Solution {
public:
    vector<string> reorderLogFiles(vector<string> logs) {
        struct  tmp
        {
            bool operator()(string a,string b){
                int i=a.find_first_of(' ');
                string temp1=a.substr(i+1);
                int j=b.find_first_of(' ');
                string temp2=b.substr(j+1);
                if(temp1!=temp2)return temp1>temp2;
                else{
                    return a.substr(0,i)>b.substr(0,j);
                }
            }
        };
        priority_queue<string,vector<string>,tmp> words;
        vector<string> number;
        for(auto i:logs){
            if(type(i)){
                number.push_back(i);
            }
            else{
                words.push(i);
            }
        }
        vector<string>ans;
        while(!words.empty()){
            ans.push_back(words.top());
            words.pop();
        }
        for(auto i:number){
            ans.push_back(i);
        }
        return ans;
    }
    bool type(string a){
        int i;
        i=a.find_first_of(' ');
        i++;
        if(a[i]<='9'&&a[i]>='0')return 1;
        return 0;
    }
};
//直接重写sort的排序规则 仿函数
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [&](const string & log1, const string & log2) {
            int pos1 = log1.find_first_of(" ");
            int pos2 = log2.find_first_of(" ");
            bool isDigit1 = isdigit(log1[pos1 + 1]);
            bool isDigit2 = isdigit(log2[pos2 + 1]);
            if (isDigit1 && isDigit2) {
                return false;
            }
            if (!isDigit1 && !isDigit2) {
                string s1 = log1.substr(pos1);
                string s2 = log2.substr(pos2);
                if (s1 != s2) {
                    return s1 < s2;
                }
                return log1 < log2;
            }
            return isDigit1 ? false : true;
        });
        return logs;
    }
};
