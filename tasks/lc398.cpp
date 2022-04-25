#include<bits/stdc++.h>
//22.4.25
/*
随机化选择相同数的下标返回
保证第一次能选到
空间十分优秀  而且保证了随机的效果
*/
class Solution {
    vector<int> &nums;
public:
    Solution(vector<int> &nums) : nums(nums) {}

    int pick(int target) {
        int ans;
        for (int i = 0, cnt = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ++cnt; // 第 cnt 次遇到 target
                if (rand() % cnt == 0) {//第一次必选
                    ans = i;
                }
            }
        }
        return ans;
    }
};
