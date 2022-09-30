#include <bits/stdc++.h>
using namespace std;

//简单逻辑问题
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(!m) return;
        int n=matrix[0].size();
        vector<int> lie(n,0);
        for(int i=0;i<m;++i){
            int lag=0;
            for(int j=0;j<n;++j){
                if(!matrix[i][j]){
                    lie[j]=1;
                    lag=1;
                }
            }
            if(lag){
                for(int j=0;j<n;++j){
                    matrix[i][j]=0;
                }
            }
        }
        for (size_t i = 0; i < n; i++)
        {
            if(lie[i]==1){
                for(int j=0;j<m;++j){
                    matrix[j][i]=0;
                }
            }
        }
        
    }
};

int main()
{
    
    system("pause");
    return 0;
}
