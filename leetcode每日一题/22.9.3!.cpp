#include <bits/stdc++.h>
using namespace std;

//典型的贪心问题  和学习贪心的初始例题一样， 按照第二个数字的大小顺序排列 看最多能取多少个
//重写sort函数时，在比较函数里面a与b，若返回true 则a在b前面
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[=](vector<int> a,vector<int> b){
            return a[1]<b[1];
        });
        int ans=0;
        int last=INT_MIN;
        for(vector<int> i:pairs){
            if(i[0]>last&&i[1]>last){
                last=i[1];
                ans++;
            }
        }
        return ans;
    }
};
//dp写法
//虽然是暴力，但是dp的思想不论在啥情况下都是精妙的
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());//必须排序
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};
//!上面的dp可以转化为贪心+二分  这种比较巧妙 很难想
//arr数组的含义是以长度为i+1的数列队列末尾可以取到的最小值
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> arr;
        for (auto p : pairs) {
            int x = p[0], y = p[1];
            if (arr.size() == 0 || x > arr.back()) {//能放就直接添加上
                arr.emplace_back(y);
            } else {//不能就看能取代那个老员工 
                int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
                arr[idx] = min(arr[idx], y);
            }
        }
        return arr.size();
    }
};

int main()
{
    
    system("pause");
    return 0;
}
