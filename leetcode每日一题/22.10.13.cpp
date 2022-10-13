#include <bits/stdc++.h>
using namespace std;

//理论上只需要记录到目前为止最大的值 如果这个值小于等于小标 就可以分一个重新计算
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        int aim=-1;
        for(int i=0;i<n;i++){
            if(aim==-1) {
                aim=arr[i];
            }
            else if(aim<arr[i]){
                aim=arr[i];
            }
            if(aim<=i){
                ans++;
                aim=-1;
            }
        }
        ans++;
        return ans;
    }
}; 

int main()
{
    
    system("pause");
    return 0;
}
