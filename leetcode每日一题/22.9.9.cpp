#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int route=0;
        for(auto i:logs){
            if(i.rfind("./",0)==0){
                continue;
            }
            else if(i.rfind("../",0)==0){
                if(route==0) continue;
                else route-=1;
            }
            else{
                route+=1;
            }
        }
        return route;
    }
};

int main()
{
    
    system("pause");
    return 0;
}
