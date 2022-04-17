#include<bits/stdc++.h>
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> Hash;
        string temp="";
        for(auto& i:paragraph){
            if(i>='A'&&i<='Z'){
                i-='A'-'a';
            }
            if(i>='a'&&i<='z'){
                temp+=i;
            }
            else{
                if(temp!=""){
                    Hash[temp]++;
                }
                temp="";
            }
        }
        //忘记了最后的结尾字符
        if(temp!=""){
            Hash[temp]++;
        }
        for(auto& i:banned){
            Hash.erase(i);
        }
        int max=0;
        string ans;
        for(auto i:Hash){
            if(i.second>=max){
                ans=i.first;
                max=i.second;
            }
        }
        return ans;

    }
};