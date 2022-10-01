#include <bits/stdc++.h>
using namespace std;



//字符串流处理string好用
class Solution {
public:
    string reorderSpaces(string text) {
        stringstream stream;
        stream<<text;//流入
        vector<string> temp;
        string a;
        int x=0;
        while (stream>>a)//流出
        {
            temp.push_back(a);
            x+=a.size();
        }
        string ans;
        if(temp.size()>1){
            int t=(text.size()-x)/(temp.size()-1);
            int y=(text.size()-x)%(temp.size()-1);
            string p(t,' ');
            cout<<t;
            cout<<y;
            for(auto i:temp){
                ans+=i;
                ans+=p;
            }
            for(int i=t;i>y;--i){
                ans.pop_back();
            }
            for(int i=t;i<y;++i){
                ans.push_back(' ');
            }
        }
        else{
            int y=text.size()-x;
            for(auto i:temp){
                ans+=i;
            }
            string p(y,' ');
            ans+=p;
        }


        return ans;
    }
};

int main()
{
    
    system("pause");
    return 0;
}
