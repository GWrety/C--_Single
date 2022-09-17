#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> hash;
        int ans=-1;
        for(int i=0;i<s.size();++i){
            if(hash.find(s[i])!=hash.end()){
                ans=max(ans,i-hash[s[i]]-1);
            }
            else{
                hash[s[i]]=i;
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
