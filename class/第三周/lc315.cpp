#include<bits/stdc++.h>
//22.3.12
/*
这道题也属于逆序对问题，如果是归并排序，需要把下标和元素组成一个pair排序，
其他操作和逆序对问题一样
归并排序一定要传引用，要不然递归没用
*/
//归并解法
class Solution {
public:
    vector<int> ans;
    vector<int> countSmaller(vector<int>& nums) {
        ans.resize(nums.size());
        vector<pair<int,int>> dir;
        for(int i=0;i<nums.size();++i){
            dir.push_back(make_pair(nums[i],i));
        }
        vector<pair<int,int>> tmp(nums.size());
        function(dir,tmp,0,nums.size()-1);
        return  ans;
    }
    void function(vector<pair<int,int>>&dir,vector<pair<int,int>>&tmp,int left,int right){
        if(left>=right) return;
        int mid=left+(right-left)/2;
        function(dir,tmp,left,mid);
        function(dir,tmp,mid+1,right);
        int low=left,high=mid+1;
        int temp=left;
        while(1){
            if(low>mid){
                while(high<=right){
                    tmp[temp]=dir[high];
                    ++temp;++high;
                }
                break;
            }
            else if(high>right){
                while(low<=mid){
                    tmp[temp]=dir[low];
                    ans[dir[low].second]+=right-mid;
                    ++temp;++low;
                }
                break;
            }
            if(dir[low].first<=dir[high].first){
                tmp[temp]=dir[low];
                ans[dir[low].second]+=high-mid-1;
                ++temp;++low;
            }
            else if(dir[low].first>dir[high].first){
                tmp[temp]=dir[high];
                ++temp;++high;
            }
        }
        for(int i=left;i<=right;++i){
            dir[i]=tmp[i];
        }
        return;
    } 
};
//树状数组
class BIT{
private:
    int n;
    vector<int> tree;
public:
    BIT(int _n):n(_n),tree(_n+1){};
    int lowbit(int a){
        return a&(-a);
    }
    void update(int x){
        while(x<=n){
            tree[x]++;
            x+=lowbit(x);
        }
    }   
    int query(int x){
        int ret=0;
        while(x){
            ret+=tree[x];
            x-=lowbit(x);
        }
        return ret;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums){
        set<int> Allnumber;
        for(auto num:nums){
            Allnumber.insert(num);
        }
        unordered_map<int,int>Hash;
        int rank=1;
        for(int num:Allnumber){
            Hash[num]=rank;
            rank++;
        }
        BIT bit(Allnumber.size());
        vector<int> ans(nums.size());
        for(int i=nums.size()-1;i>=0;--i){
            ans[i]=bit.query(Hash[nums[i]]-1);
            bit.update(Hash[nums[i]]);
        }
        return ans;
        
    }
};