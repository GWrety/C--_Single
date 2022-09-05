#include<bits/stdc++.h>
//22.4.17  2/4
#define all(x) x.begin(),x.end()
//前两道签到题
class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string temp="";
            int lag=0,ret=0;
            for(auto& i:s){
                if(lag==k){
                    temp+=to_string(ret);
                    ret=0;
                    lag=0;
                }
                ret+=i-'0';
                lag++;
            }
            temp+=to_string(ret);
            s=temp;
        }
        return s;
    }
};

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> Hash;
        for(auto& i:tasks){
            Hash[i]++;
        }
        int ans=0;
        for(auto &i:Hash){
            int temp=0;
            int x=i.second%3;
            if(!x){
                ans+=i.second/3;
                continue;
            }
            else{
                if(x==2){
                    ans+=i.second/3+1;
                }
                else if(x==1){
                    if(i.second==1)return -1;
                    ans+=i.second/3+1;
                }
            }
        }
        return ans;
    }
};

/*
纯纯的暴力穷举过不了！
还是应该找2和5的个数
*/
/* class Solution {
vector<vector<int>> Dir;
int ans=0;
int m;
int n;
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        Dir.push_back({0,1});
        Dir.push_back({0,-1});
        Dir.push_back({1,0});
        Dir.push_back({-1,0});
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                func(grid,i+Dir[0][0],j+Dir[0][1],0,0,grid[i][j]);
                func(grid,i+Dir[1][0],j+Dir[1][1],1,0,grid[i][j]);
                func(grid,i+Dir[2][0],j+Dir[2][1],2,0,grid[i][j]);
                func(grid,i+Dir[3][0],j+Dir[3][1],3,0,grid[i][j]);
            }
        }
        return ans;
    }
    void func(vector<vector<int>>&grid,int x,int y,int dir,int lag,unsigned long long now){
        if(x<0||x>=m||y<0||y>=n){
            ans=max(ans,getnum(now));
            return;
        }
        if(!lag){
            if(dir==0||dir==1){
                func(grid,x+Dir[2][0],y+Dir[2][1],2,1,now*grid[x][y]);
                func(grid,x+Dir[3][0],y+Dir[3][1],3,1,now*grid[x][y]);
            }
            else if(dir==2||dir==3){
                func(grid,x+Dir[0][0],y+Dir[0][1],0,1,now*grid[x][y]);
                func(grid,x+Dir[1][0],y+Dir[1][1],1,1,now*grid[x][y]);
            }
        }
        func(grid,x+Dir[dir][0],y+Dir[dir][1],dir,lag,now*grid[x][y]);
    }
    int getnum(unsigned long long x){
        int temp=0;
        while(x%10==0){
            temp++;
            x/=10;
        }
        return temp;
    }
}; */
class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> f2(n + 1), g2(n + 1), f5(n + 1), g5(n + 1);
        for (int i = 0; i <= n; i++) f2[i] = g2[i] = f5[i] = g5[i] = vector<int>(m + 1);
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
            int x = grid[i - 1][j - 1];
            int two = 0, five = 0;
            while (x % 2 == 0) two++, x /= 2;
            while (x % 5 == 0) five++, x /= 5;
            f2[i][j] = f2[i][j - 1] + two;
            g2[i][j] = g2[i - 1][j] + two;
            f5[i][j] = f5[i][j - 1] + five;
            g5[i][j] = g5[i - 1][j] + five;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
            // 从左边出发，到上边结束
            ans = max(ans, min(f2[i][j] + g2[i - 1][j], f5[i][j] + g5[i - 1][j]));
            // 从左边出发，到下边结束
            ans = max(ans, min(f2[i][j] + g2[n][j] - g2[i][j], f5[i][j] + g5[n][j] - g5[i][j]));
            // 从右边出发，到上边结束
            ans = max(ans, min(f2[i][m] - f2[i][j] + g2[i][j], f5[i][m] - f5[i][j] + g5[i][j]));
            // 从右边出发，到下边结束
            ans = max(ans, min(f2[i][m] - f2[i][j] + g2[n][j] - g2[i - 1][j], f5[i][m] - f5[i][j] + g5[n][j] - g5[i - 1][j]));
        }
        return ans;
    }
};
