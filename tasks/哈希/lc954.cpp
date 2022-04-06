#include<bits/stdc++.h>
//22.4.1
/*
给定一个长度为偶数的整数数组 arr，只有对 arr 进行重组后可以满足 “对于每个 0 <= i < len(arr) / 2，
都有 arr[2 * i + 1] = 2 * arr[2 * i]” 时，
返回 true；否则，返回 false。
*/
/*
纠正了hash查找错误写法
但开始时没考虑到1248这种情况  忘记先排序了
但这么写效果很差
综合看题解之后发现，其实大家解法都差不多
但他们把元素都先放进去如果遇到不满足的就直接返回false这样在时间效率上会快一点
*/
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> hash;
        sort(arr.begin(),arr.end());//1248
        for(auto &x:arr){
            
            if(hash.find(2*x)!=hash.end()){
                hash[2*x]--;
                if(hash[2*x]==0){
                    hash.erase(2*x);
                }
                
            }
            else if(!(x%2)&&hash.find(x/2)!=hash.end()){
                hash[x/2]--;
                if(hash[x/2]==0){
                    hash.erase(x/2);
                }
            }
            else{
                hash[x]++;
            }
        }
        return hash.empty();
    }
};