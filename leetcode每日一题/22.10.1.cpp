#include <bits/stdc++.h>
using namespace std;
//很简单 每次识别 在最后的时刻判断以下是不是一个数字
class Solution {
public:
    string reformatNumber(string number) {
        string ans="";
        int lag=0;
        string temp="";
        for(auto i:number){
            if(isdigit(i)){
                if(lag==3){
                    if(ans.size())
                        ans+="-";
                    ans+=temp;
                    lag=0;
                    temp="";
                }
                temp+=i;
                lag++;
            }
        }
        if(lag==3){
            if(ans.size())
                ans+="-";
            ans+=temp;
            lag=0;
        }
        if(lag==1){
            string temp1=ans.substr(0,ans.size()-1);
            temp1+="-";
            temp1+=ans[ans.size()-1];
            temp1+=temp;
            ans=temp1;   
        }
        if(lag==2){
                          if(ans.size())
            ans+="-";
            ans+=temp;
        }
        return ans;
    }
};


int main()
{
    
    system("pause");
    return 0;
}
