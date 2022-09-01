#include<bits/stdc++.h>



//思路就是先统计数字频率，如果不同直接false  如果相同直接true
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size()!=arr.size())return false;
        multiset<int> set1;
        for (size_t i = 0; i < target.size(); i++)
        {
            set1.insert(target[i]);
        }
        multiset<int> set2;
        for (size_t i = 0; i < arr.size(); i++)
        {
            set2.insert(arr[i]);
        }
        if(set1!=set2) return false;
        return true;
    }
};