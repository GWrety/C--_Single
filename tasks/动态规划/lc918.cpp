#include<bits/stdc++.h>
/*
    搞不懂这题和动态规划有啥关系
    摒弃思路限制，先想解决办法
    感觉想法不太顺畅，对于一些特殊情况没什么好的解决办法
    总之就是如何把数组分散在两边的识别出来（这个难点）
    我原来那种写法没有一个通用的解决办法处理不同情况。
健豪法:
    扔掉最大的负数字串，再排一遍
分治不好写了

看题解：
    这种题的题解都是降维打击性的，整个思路和公式的推导都值得学习
    太巧妙了，时刻注意全为负数的情况
    反正如果最大子序列在中间就和第一题一样
    如果在两边被分开的化，
        max(前缀数组+后缀数组)
        = max(数组总和 - subarray) subarray指的是前缀数组和后缀数组中间的数组
        = 数组总和 + max(-subarray) 数组总和是不变的，直接提出来
        = 数组总和 - min(subarry) 。。。这个都懂吧，把负号提出来，max变成min
    也就是说最大环形字数组和最小环形子数组的并集是整个数组
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int& a : A) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
}
};

