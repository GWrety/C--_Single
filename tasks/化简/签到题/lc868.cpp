#include<bits/stdc++.h>
class Solution {
public:
    int binaryGap(int n) {
        int pre=-1;
        int ans=0;
        int now=0;
        while(n){
            if(n&1){
                if(pre!=-1){
                    ans=max(ans,now-pre);
                }
                pre=now;
            }
            now++;
            n>>=1;
        }
        return ans;
    }
};

