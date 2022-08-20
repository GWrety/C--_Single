#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    system("pause");
    return 0;
}

// 2022.8.19
//这道题如果是数据量够小,或询问次数够少.那么枚举的方法是最优解
//但如果这道题数据量很大,就需要使用 差分 或者二分查找等进行优化
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int size=startTime.size();
        int answer=0;
        for(int i=0; i<size; i++){
            if(startTime[i]>queryTime) continue;
            if(endTime[i]>=queryTime) answer++;
        }
        return answer;
    }
};
