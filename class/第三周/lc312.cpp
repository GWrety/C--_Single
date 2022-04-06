#include<bits/stdc++.h>
//22.3.12
/*
有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。
 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。
求所能获得硬币的最大数量。
*/
/*
这个动态规划比较难想
如果抓住动态规划的思路出不来（一维，二维，三维），还是从记忆化递归搜索出发剪枝吧
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> rec(n + 2, vector<int>(n + 2));
        vector<int> val(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            val[i] = nums[i - 1];
        }
        //就是一个矩阵
        //这个从下向上算
        //优化 上一行能用下一行已经有的，这一行能用前面列算过的
        /* for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j <= n + 1; j++) {
                for (int k = i + 1; k < j; k++) {
                    int sum = val[i] * val[k] * val[j];
                    sum += rec[i][k] + rec[k][j];//前一项是用一行，后一项是同一列
                    rec[i][j] = max(rec[i][j], sum);
                }
            }
        }
        for(int i=0;i<rec.size();++i){
            for(int j=0;j<rec[i].size();++j){
                cout<<rec[i][j]<<" ";
            }
            cout<<endl;
        } */
        //首先同一行的使用是没有问题的，但对于同一列，下面一定有参考
        //这个是从左向右算
        //优化：下一列能用上一列算过的，这一行能用下一行算过的
        for(int i=2;i<=n+1;++i){
            for(int j=i-2;j>=0;--j){
                for(int k=j+1;k<i;++k){
                    int sum=val[j]*val[k]*val[i];
                    sum+=rec[j][k]+rec[k][i];//前一项同一行，后一项同一列
                    rec[j][i]=max(rec[j][i],sum);
                }
            }
        }
        //首先同一行的使用是没有问题的，但对于同一列，想借用的是下一行的列 必须从下向上算
        /*
        总体来说 方向只有两个 一个向上一个向右  两种模式
        */
        /*for(int i=0;i<rec.size();++i){
            for(int j=0;j<rec[i].size();++j){
                cout<<rec[i][j]<<" ";
            }
            cout<<endl;
        } */
        return rec[0][n + 1];
    }
};

int main(){
    vector<int> nums={3,1,5,8};
    Solution c;
    c.maxCoins(nums);
}


