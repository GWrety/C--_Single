#include<bits/stdc++.h>
//22.3.13
/*
电子游戏“辐射4”中，任务 “通向自由” 要求玩家到达名为 “Freedom Trail Ring” 的金属表盘，并使用表盘拼写特定关键词才能开门。
给定一个字符串 ring ，表示刻在外环上的编码；给定另一个字符串 key ，表示需要拼写的关键词。您需要算出能够拼写关键词中所有字符的最少步数。
最初，ring 的第一个字符与 12:00 方向对齐。您需要顺时针或逆时针旋转 ring 以使 key 的一个字符在 12:00 方向对齐，然后按下中心按钮，
以此逐个拼写完 key 中的所有字符。
旋转 ring 拼出 key 字符 key[i] 的阶段中：

您可以将 ring 顺时针或逆时针旋转 一个位置 ，计为1步。旋转的最终目的是将字符串 ring 的一个字符与 12:00 方向对齐，
并且这个字符必须等于字符 key[i] 。
如果字符 key[i] 已经对齐到12:00方向，您需要按下中心按钮进行拼写，这也将算作 1 步。按完之后，
您可以开始拼写 key 的下一个字符（下一阶段）, 直至完成所有拼写。

*/
/*
纯暴力深度搜索过不了
动态规划应该不好想，就没试，学习一下题解思路；
优化点：
岔路口之后子树会重复，记下来减少冲股份计算
*/
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<int> pos[26];//统计各个字母出现的位置
        for (int i = 0; i < n; ++i) {//
            pos[ring[i] - 'a'].push_back(i);
        }
        vector<vector<int>> dp(m, vector<int>(n, 0x3f3f3f3f));
        for (auto& i: pos[key[0] - 'a']) {
            dp[0][i] = min(i, n - i) + 1;
        }
        for (int i = 1; i < m; ++i) {
            for (auto& j: pos[key[i] - 'a']) {
                for (auto& k: pos[key[i - 1] - 'a']) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
                }
            }
        }
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};

//失败  纯暴力
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ans=INT_MAX;
        function(ring,key,0,0,ans,0);
        return ans;
    }
    void function(string& ring,string& key,int mid,int aim,int& ans,int step){
        if(aim==key.size()){
            ans=min(ans,step);return;
        } 
        int n=ring.size();

        int temp=mid;
        int F=step;
        for(int i=0;i<=ring.size()/2;++i){
            if(key[aim]==ring[temp]){
                ++F;
                function(ring,key,temp,aim+1,ans,F);
            }
            ++F;
            temp=(temp+1+n)%n;
        }
        temp=mid;
        F=step;
        for(int i=0;i<(ring.size()-1)/2;++i){
            ++F;
            temp=(temp-1+n)%n;
            if(key[aim]==ring[temp]){
                ++F;
                function(ring,key,temp,aim+1,ans,F);
            }
        }
    }
};

