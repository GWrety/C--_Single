#include <bits/stdc++.h>
// 22.5.8
/*
原地哈希
在原序列上用下标进行哈希
遍历完成后i-n代表i+1出现的次数
*/
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n;)
        {
            if (nums[i] > n)//此位置已经是桶，跳过
                i++;
            else if (nums[nums[i] - 1] > n)//该元素理应在的位置已经为桶
            {
                nums[nums[i] - 1]++;
                if (nums[nums[i] - 1] == n + 3)
                    ans.push_back(nums[i]);
                if(nums[i]<n)
                    nums[i] = n + 1;//将自己的位置设为桶
                ++i;
            }
            else//这种情况下是该元素对应的桶位置在数组后面
            {
                if (i == nums[i] - 1)//如果桶的位置是自己的位置
                {
                    nums[i] = n + 2;
                    ++i;
                }
                else//桶的位置在后面
                {
                    int temp = nums[nums[i] - 1];
                    nums[nums[i] - 1] = n + 2;
                    nums[i] = temp;
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> a = {4, 3, 2, 7, 8, 2, 3, 1};
    Solution t;
    t.findDuplicates(a);
    return 0;
}