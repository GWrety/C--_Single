#include<bits/stdc++.h>
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        queue<int> aim;
        for(int i=0;i<n;++i){
            if(nums[i]%2){
                aim.push(i);
            }
            else{
                if(!aim.empty()){
                    int temp=nums[i];
                    int t=aim.front();
                    aim.pop();
                    nums[i]=nums[t];
                    nums[t]=temp;
                    aim.push(i);
                }
            }
        }
        return nums;
    }   
};