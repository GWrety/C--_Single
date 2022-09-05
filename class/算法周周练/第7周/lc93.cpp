#include<bits/stdc++.h>
/*
解密ip地址
简单回溯剪枝
*/
class Solution {
    vector<string> ans;
    int n;
public:
    vector<string> restoreIpAddresses(string s) {
        n=s.size();
        func(s,0,0,"");
        return ans;
    }
    void func(string& s,int pos,int now,string temp){
        if(pos>=n)return;
        if(now==3){
            if(s[pos]=='0'){
                if(pos==n-1) ans.push_back(temp+"0");
                return;
            }
            string a=s.substr(pos);
            if(stoi(a)<=255){
                ans.push_back(temp+a);
            }
            return;
        }
        if(s[pos]=='0'){
            if(issafe(now+1,pos+1))
            func(s,pos+1,now+1,temp+"0.");
        }
        else{
            for(int i=1;i<4;++i){
                if(pos+i<n&&issafe(now+1,pos+i)){
                    string a=s.substr(pos,i);
                    if(stoi(a)<=255){
                        func(s,pos+i,now+1,temp+a+".");
                    }
                }
            }
        }
    }
    bool issafe(int now,int pos){
        int x=4-now;
        if(n-pos>x*3) return false;
        return true;
    }
};