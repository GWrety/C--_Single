#include <bits/stdc++.h>
using namespace std;
//627

//初始状态是 n个打开的灯
//所有的操作组合有pow(4,presses)  
// 穷举的话  1 2 3 4 
//模拟前4位就行  
//但位运算有点复杂  下面是一种比较牛的写法
//脑子乱乱的暂时不考虑
class Solution {
public:
    int flipLights(int n, int presses) {
        if (presses > 2 && n > 2) return 8;
        if (n < 3) return 1 + (presses > 0) * n + (presses > 1 && n > 1);
        else return 1 + 3 * presses;
    }
};

int main()
{    
    system("pause");
    return 0;
}
