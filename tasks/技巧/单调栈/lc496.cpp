#include<bits/stdc++.h>
//22.3.4
/*
nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。
给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。
对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定 nums2[j] 的 下一个更大元素 。
如果不存在下一个更大元素，那么本次查询的答案是 -1 。
返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。
*/
/*
单调栈使用
单调栈就是一个单调递增或递减的栈  用于找附近的最值元素
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>ans(n);
        unordered_map<int,int>hash;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;--i){
            while(!st.empty()&&st.top()<nums2[i]) st.pop();
            if(!st.empty()) hash[nums2[i]]=st.top();
            else{
                hash.insert(nums2[i],-1);
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<n;i++){
            ans[i]=hash[nums1[i]];
        }
        return ans;
    }
};