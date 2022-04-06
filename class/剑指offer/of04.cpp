#include<bits/stdc++.h>
//22.2.26
/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
/*
    这道题上课讲过了，
    听到一个女同学说二分，感觉意思不是很大，虽然可能会跳转，但执行的判断语句会很多，但依然是最好的解法
    一开始没抓住列的规则，没想到约束矩阵，听了它的建议发现可以约束矩阵，总之还是借鉴别人的思路
*/
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int m=matrix[0].size(),n=matrix.size();
        if(m==0||target<matrix[0][0]) return false;
        int a=0,b=m-1;
        while(1){
            if(a==n)break;
            while(b>=0&&matrix[a][b]>target){
                    b--;
            }
            if(b<0)break;
            if(matrix[a][b]==target) return true;
            a++;
        }
        return false;
    }
};