#include <bits/stdc++.h>
using namespace std;
//用一个hash表存放频率
//排序数组是重写排序函数 用hash中的数值作为参照
//但在写sort函数时
//[&] : capture all external variable by reference:通过引用的方式获取所有外部变量
//[=] : capture all external variable by value：获取所有外部变量
//!如果在sort比较函数哪里不用&的话，会报错。暂时不知道什么原因
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto i: nums){
            map[i]++;
        }
        sort(nums.begin(),nums.end(),[&](int a,int b)->bool{
            if(map[a]!=map[b]){
                return map[a]<map[b];
            }
            else{
                return a>b;
            }
        });
        return nums;
    }
};

int main()
{
    
    system("pause");
    return 0;
}
