#include<bits/stdc++.h>
//22.2.21
/*
在一个 n x n 的国际象棋棋盘上，一个骑士从单元格 (row, column) 开始，并尝试进行 k 次移动。行和列是 从 0 开始 的，所以左上单元格是 (0,0) ，
右下单元格是 (n - 1, n - 1) 。
象棋骑士有8种可能的走法，如下图所示。每次移动在基本方向上是两个单元格，然后在正交方向上是一个单元格。

每次骑士要移动时，它都会随机从8种可能的移动中选择一种(即使棋子会离开棋盘)，然后移动到那里。
骑士继续移动，直到它走了 k 步或离开了棋盘。
返回 骑士在棋盘停止移动后仍留在棋盘上的概率 。
*/
/*
    暴力递归不行，k=30就爆掉了
    感觉是递归问题，递归优化？？？
    思路阻塞 看题解
    动态规划（感觉就是把递归优化从底层优化 ，把原来的递归优化也行 叫记忆化搜索....）
    但不能算成功的次数，必须按每个格子有多少步的概率算。
    对于下列这两种解法 动态规划似乎效果好一点
*/
//记忆化搜索
class Solution {
public:
    int dr[8] = {-2,-2,-1,-1,1,1,2,2};
    int dc[8] = {1,-1,2,-2,2,-2,1,-1};
    unordered_map<int, unordered_map<int, double>> mem;//标签
    //这个int就很关键，把二维降成了一维

    double knightProbability(int n, int k, int row, int column) {
        if (k == 0) return 1;
        if (mem[row*n+column].find(k) != mem[row*n+column].end()) return mem[row*n+column][k];

        double prb = 0;
        for (int d = 0; d < 8; d++) {
            int r = row + dr[d];
            int c = column + dc[d];
            if (r >= n || c >= n || r < 0 || c < 0) continue;
            prb += knightProbability(n, k-1, r, c) / 8;
        }

        mem[row*n+column][k] = prb;
        return prb;
    }
};

//动态规划题解  
class Solution {
public:
    vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

    double knightProbability(int n, int k, int row, int column) {

        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n)));
        
        for (int step = 0; step <= k; step++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (step == 0) {
                        dp[step][i][j] = 1;
                    } 
                    else {
                        for (auto & dir : dirs) {
                            int ni = i + dir[0], nj = j + dir[1];
                            if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                                dp[step][i][j] += dp[step - 1][ni][nj] / 8;
                            }
                        }
                    }
                }
            }
        }
        return dp[k][row][column];
    }
};
