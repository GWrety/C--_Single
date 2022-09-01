#include <bits/stdc++.h>
using namespace std;


//这不找最大的就行了吗
//比较好的做法是双指针，同时维护最大值和次大值
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater());
        return (nums[0]-1)*(nums[1]-1);
    }
};

int main()
{
    
    system("pause");
    return 0;
}
