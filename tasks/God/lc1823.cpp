#include<bits/stdc++.h>
//22.5.4
/*
模拟的效果很差啊  有更好的数学方法
约瑟夫环问题：
用链表移动执政比队列的模拟效果好很多
但如果只是求最后一个赢家，可以直接数学公式推导

*/
//傻瓜队列模拟
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>arr;
        for(int i=0;i<n;++i){
            arr.push(i+1);
        }
        while(arr.size()!=1){
            for(int i=1;i<k;++i){
                arr.push(arr.front());
                arr.pop();
            }
            arr.pop();
        }
        return arr.front();
    }
};
//数学公式推导  效率很高
class Solution {
public:
    int findTheWinner(int n, int k) {
        return n == 1 ? 1 : (k + findTheWinner(n - 1, k) - 1) % n  + 1;//这个最后的+1 
    }
};
//在下标从0开始的基本问题上解决----好理解
class Solution {
public:
    int findTheWinner(int n, int k) {
        return fun(n,k)+1;
    }
    int fun(int n,int k){//n个人 下标从0开始
        return n == 1 ? 0 : (fun(n - 1, k)+k) % n;//这很好理解 
    }
};
//迭代版本
class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 1;
        for (int i = 2; i <= n; i++) {//从下到上，动态规划
            winner = (k + winner - 1) % i + 1;
        }
        return winner;
    }
};