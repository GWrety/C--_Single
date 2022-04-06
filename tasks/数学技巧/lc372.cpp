#include<bits/stdc++.h>
//22.2.23
/*
    只会把整型转换为2进制快速幂，对于数组形态的数不知道咋处理
    https://www.desgard.com/algo/docs/part2/ch01/3-matrix-quick-pow/（这篇文章写的很好）
    同时知道了快速幂可以和取模的交换律结合起来（像个递归，需要仔细考虑）
    % * / 优先级相同，从左向右算
*/
//倒序，快速幂（变形），直接以10进制为底
class Solution {
    const int MOD = 1337;

    int pow(int x, int n) {
        int res = 1;
        while (n) {
            if (n % 2) {
                res = (long) res * x % MOD;
            }
            x = (long) x * x % MOD;
            n /= 2;
        }
        return res;
    }

public:
    int superPow(int a, vector<int> &b) {
        int ans = 1;
        for (int i = b.size() - 1; i >= 0; --i) {
            ans = (long) ans * pow(a, b[i]) % MOD;
            a = pow(a, 10);
        }
        return ans;
    }
};
