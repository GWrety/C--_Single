#include <bits/stdc++.h>
//22.2.15
/*
给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。

幸运数是指矩阵中满足同时下列两个条件的元素：

在同一行的所有元素中最小
在同一列的所有元素中最大
*/
//memset用法，被坑了

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> answer;
        int* maxline=new int [matrix[0].size()];
        memset(maxline,1,matrix[0].size()*sizeof(int)); 
        for(int i=0;i<matrix.size();i++){
            int c=maxline[i];
        }
        for(int i=0;i<matrix.size();i++){
            int temp=INT_MAX;
            int templine=-1;
            for(int j=0;j<matrix[i].size();j++){
                if(temp>matrix[i][j]){
                    temp=matrix[i][j];
                    templine=j;
                }
            }
            if(maxline[templine]==0x01010101){
                int min=INT_MIN;
                for(int k=0;k<matrix.size();k++){
                    if(matrix[k][templine]>min){
                        min=matrix[k][templine];
                        maxline[templine]=matrix[k][templine];
                    }
                }
            }
            if(temp==maxline[templine]){
                    answer.push_back(temp);
            }
        }
        return answer;
    }
};

