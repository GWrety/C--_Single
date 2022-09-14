#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        double sum=0;
        for(int i=arr.size()*0.05;i<arr.size()*0.95;++i){
            sum+=arr[i];
        }
        return sum/(arr.size()*0.9);
    }
};

//快速选择解法
class Solution {
public:
    double trimMean(vector<int>& arr) {
        auto dis = arr.size() / 20;
        //将第k个移动到arr.begin()  + dis位置 前面都是小于它的，后面都是大于它的
        nth_element(arr.begin(),  arr.begin()  + dis, arr.end());
        //rbegin指向最后一个元素 rend指向第一个元素
        //greater  拍完是 a>b   迭代器前面的 大于迭代器后面的
        nth_element(arr.rbegin(), arr.rbegin() + dis, arr.rend(), greater{});
        return accumulate(arr.begin() + dis, arr.end() - dis, 0.0) / (arr.size() * 0.9);
    }
};
int main()
{
    
    system("pause");
    return 0;
}
