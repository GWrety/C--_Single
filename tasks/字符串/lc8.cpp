#include<bits/stdc++.h>
class Solution {
public:
        int myAtoi(string s) {
            int ans=0;
            int n=s.size();
            int lag=0;
            for(int i=0;i<n;++i){
                if(s[i]=='-'||s[i]=='+'){
                    if(s[i]=='-') lag=1;
                    ans=function(i+1,n,s,lag);
                    break;
                }
                else if(s[i]<='9'&&s[i]>='0'){
                    ans=function(i,n,s,lag);
                    break;
                }
                else if(s[i]!=' '){
                    break;
                }
            }
            return ans;
        }
        int function(int x,int n,string &s,int lag){
            int temp=0;
            long long t=0;
            for(;x<n;++x){
                if(s[x]>='0'&&s[x]<='9'){
                    t=temp*(long long)10+s[x]-'0';
                    if(!lag&&t>=INT_MAX){
                        return INT_MAX;
                    }
                    else if(lag&&(0-t)<=INT_MIN){
                        return INT_MIN;
                    }
                    else{
                        temp*=10;
                        temp+=s[x]-'0';
                    }
                }
                else{
                    break;
                }
            }
            return  lag==1?0-temp:temp;
        }
};

