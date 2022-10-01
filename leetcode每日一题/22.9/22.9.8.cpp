#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int aim=n;
        int t=k/2;
        int p=k%2;
        
        //完成这一步的序列后是一个奇数
        while (t>0)
        {
            ans.push_back(aim);
            ans.push_back(n+1-aim);
            aim--;
            t--;
        }
        while(ans.size()<n){
            //奇数要补两个
            if(p)ans.push_back(aim--);
            //偶数后面只需要补一个
            else{
                ans.push_back(n+1-aim);
                aim--;
            }
        }
        return ans;
    }
};

int main()
{
    
    system("pause");
    return 0;
}
