#include <bits/stdc++.h>
using namespace std;


//记住当前的最大差距，如果数不够直接填进去 每次插入一个就排序 前后一个总有一个最大值 
//如果满了，切这个数小就看 前后那个大？ 一样大踢出去后面的 再排列
//上面是没顺序的做法，如果arr有序 那么找打和x最近的一个数 前后探测出x个即是答案
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        //找到距离最小的位置
        //这个是时间复杂度为n的找法，其实可以用二分来找
        //int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        // int left = right - 1;

        int aim=-1;
        int distance=INT_MAX;
        for (size_t i = 0; i < arr.size(); i++)
        {
            if(abs(arr[i]-x)<distance){
                aim=i;
                distance=abs(arr[i]-x);
            }
        }
        //前后探测
        int left= aim;
        int right =aim+1;
        while(ans.size()<k){
            if(left<0){
                ans.push_back(arr[right]);
                right++;
            } 
            else if(right>=arr.size()){
                ans.push_back(arr[left]);
                left--;
            } 
            else{
                if(abs(arr[left]-x)<=abs(arr[right]-x)){
                    ans.push_back(arr[left]);
                    left--;
                }
                else{
                    ans.push_back(arr[right]);
                    right++;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//一种代码较短的暴力写法
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](int a, int b) -> bool {
            return abs(a - x) < abs(b - x) || abs(a - x) == abs(b - x) && a < b;
        });
        sort(arr.begin(), arr.begin() + k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};

//直接二分，查找区间的最左端
class Solution {
public:
    vector<int> findClosestElements(const vector<int>& arr, int k, int x) {
        int lo = 0, hi = arr.size() - k;
        while (lo < hi) {
            const int mi = (lo + hi) / 2;
            if (x - arr[mi] > arr[mi + k - 1] - x)
                lo = mi + 1;
            else hi = mi;
        }
        if (lo > 0 && abs(arr[lo - 1] - x) <= abs(arr[lo + k - 1] - x))
            --lo;
        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};

int main()
{
    
    system("pause");
    return 0;
}


