#include <bits/stdc++.h>
using namespace std;


//如果只是找357相乘也不一定 
//7*7是比3*3*3大的
//当然肯定可以使用最小堆用来枚举，但效率很低
//实际上就是求 3^a*5^b*7^c  满足该式的最小k个数
class Solution {
public:
    //动态规划  非常巧妙
    //todo 咱也不知道为啥  就是对
    int getKthMagicNumber(int k) {
        vector<int> dp(k + 1);
        dp[1] = 1;
        int p3 = 1, p5 = 1, p7 = 1;
        for (int i = 2; i <= k; i++) {
            int num3 = dp[p3] * 3, num5 = dp[p5] * 5, num7 = dp[p7] * 7;
            dp[i] = min(min(num3, num5), num7);
            if (dp[i] == num3) {
                p3++;
            }
            if (dp[i] == num5) {
                p5++;
            }
            if (dp[i] == num7) {
                p7++;
            }
        }
        return dp[k];
    }
};


int main()
{
    
    system("pause");
    return 0;
}
