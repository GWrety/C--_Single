#include <bits/stdc++.h>
using namespace std;


//如果用辅助数组就很简单，设置一个左右指针 逐步移动即可
//暂时没想到比较简单的原地调换的方法   可以直接计算目标位置， 但需要下面两种算法迂回
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int left=0;
        int right=n;
        int lag=1;
        while(ans.size()<nums.size()){
            //其实这里 两个都操作一下就好了 ，没必要分出来 每次都是加left 加right  然后都++
            if(!lag){
                ans.push_back(nums[right]);
                right++;
                lag=1;
            }
            else{
                ans.push_back(nums[left]);
                left++;
                lag=0;
            }
        }
        return ans;
    }
};


//利用数字有最大值的性质，用他的高位来存取 通过计算后得到的目标值，
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        for(int i = 0; i < 2 * n; i ++){
            int j = i < n ? 2 * i : 2 * (i - n) + 1;
            nums[j] |= (nums[i] & 1023) << 10;
        }
        for(int& e: nums) e >>= 10;
        return nums;
    }
};


//也是一种使用了数字非负的方法，主要是标记到底是不是正确的位置
//看似不断交换，实际是也是和上面哪一种一样 遍历一遍
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        for(int i = 0; i < 2 * n; i ++)
            if(nums[i] > 0){
                
                // j 描述当前的 nums[i] 对应的索引，初始为 i
                int j = i; 

                while(nums[i] > 0){

                    // 计算 j 索引的元素，也就是现在的 nums[i]，应该放置的索引
                    j = j < n ? 2 * j : 2 * (j - n) + 1; 

                    // 把 nums[i] 放置到 j 的位置，
                    // 同时，把 nums[j] 放到 i 的位置，在下一轮循环继续处理
                    swap(nums[i], nums[j]); 

                    // 使用负号标记上，现在 j 位置存储的元素已经是正确的元素了 
                    nums[j] = -nums[j]; 
                }
            }

        for(int& e: nums) e = -e;
        return nums;
    }
};


int main()
{
    
    system("pause");
    return 0;
}
