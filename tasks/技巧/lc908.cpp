#include<bits/stdc++.h>
//22.4.30
/*
必须修改最大最小的元素，但得保证别的数不影响
总是差一点
当把最大的差距能缩小后，中间的数一定能到准线上，或者到差值范围内！
*/
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        return maxNum - minNum <= 2 * k ? 0 : maxNum - minNum - 2 * k;
    }
};