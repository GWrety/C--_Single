#include <bits/stdc++.h>
using namespace std;


//找一个x使得数组种大于等于x的元素恰好有x个   如果没有就返回-1
//简单的就是暴力查找 优化一点就是找到最大和最小值二分查找
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int max=-1;
        int min=1000;
        unordered_map<int,int> map;
        for(auto i:nums){
            //有可能不在界限之内
            if(i<min) min=i;
            if(i>max) max=i;
            map[i]++;
        }
        //此处min 如果是负数的话， 在比较nums.size()和min的时候会出现错误  不仅不能加减 还不能比较无符号数和负数的大小 
        min=nums.size()<min?nums.size():min-1;
        max=nums.size()>max+1?nums.size():max+1;
        int ans=-1;
        while (min<=max)
        {
            int mid=(min+max)/2;
            int num=0;
            for(auto i:map){
                if(i.first>=mid)num+=i.second;
            }
            if(num>mid){
                min=mid+1;
            }
            else if(num<mid){
                max=mid-1;
            }
            else{
                ans=mid;
                break;
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

