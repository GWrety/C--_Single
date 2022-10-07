#include <bits/stdc++.h>
#include<regex>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=nums[0];
        int temp=0;
        int pres=0;
        for(auto i:nums){
            if(pres!=0&&i>pres){
                temp+=i;
            }
            else{
                temp=i;
            }
            ans=max(ans,max(temp,i));
            pres=i;
        }
        return ans;
    }
};

int main()
{

    system("pause");
    return 0;
}
