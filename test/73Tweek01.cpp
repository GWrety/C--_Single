#include<bits/stdc++.h>
//22.3.5
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int> map;
        vector<int> ans;
        int lag=0;
        for(int i=0;i<nums.size();++i){
            map[nums[i]]++;
            if(lag){
                ans.push_back(nums[i]);
                lag=0;
            }
            if(key==nums[i]){
                lag=1;
            }
        }
        int temp=INT_MIN;
        int ret;
        for(int i=0;i<ans.size();++i){
            if(map[ans[i]]>temp){
                temp=map[ans[i]];
                ret=ans[i];
            }
        }
        return ret;
    }
};
//操   我为什么不放下标呢  shit  还是题目的抽象没看懂，总以为让他带着一个大的数排前面（这不是稳定就不可能实现），其实就是下标小的在前面
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>>nums2;
        for(int i=0;i<nums.size();++i){
            int temp=nums[i];
            int wit=0;int r=0;
            if(temp==0){
                nums2.push_back(make_pair(mapping[0],i));
                continue;
            }
            while(temp!=0){
                wit+=mapping[temp%10]*pow(10,r);
                temp/=10;++r;
            }
            nums2.push_back(make_pair(wit,i));
        }
        sort(nums2.begin(),nums2.end());
        vector<int>ans;
        for(auto &s:nums2){
            ans.push_back(nums[s.second]);
        }        
        return ans;
    }
};




