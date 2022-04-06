#include<bits/stdc++.h>
//  22.2.21
/*
n 张多米诺骨牌排成一行，将每张多米诺骨牌垂直竖立。在开始时，同时把一些多米诺骨牌向左或向右推。

每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。

如果一张垂直竖立的多米诺骨牌的两侧同时有多米诺骨牌倒下时，由于受力平衡， 该骨牌仍然保持不变。

就这个问题而言，我们会认为一张正在倒下的多米诺骨牌不会对其它正在倒下或已经倒下的多米诺骨牌施加额外的力。

给你一个字符串 dominoes 表示这一行多米诺骨牌的初始状态，其中：

dominoes[i] = 'L'，表示第 i 张多米诺骨牌被推向左侧，
dominoes[i] = 'R'，表示第 i 张多米诺骨牌被推向右侧，
dominoes[i] = '.'，表示没有推动第 i 张多米诺骨牌。
返回表示最终状态的字符串。
*/
/*
    最初版本是依次遍历  扫一遍执行下一步 因为是l到r扫要特殊处理一下
        这种解法：时间复杂度很大，但空间复杂度优秀(有点垃圾)
    再写一种一次遍历出结果的：
        效果很好

*/
class Solution {//模拟运行版
public:
    string pushDominoes(string dominoes) {
        int is_change=1;
        int L_fall=1;
        while(is_change){
            is_change=0;
            for(int i=0;i<dominoes.size();i++){
                if(dominoes[i]!='.'){
                    if(dominoes[i]=='L'){
                        if(i-1>=0&&dominoes[i-1]=='.'){
                            if(L_fall){
                                dominoes[i-1]='L';
                                is_change=1;
                            }
                            L_fall=1;
                        }
                    }
                    else if(dominoes[i]=='R'){
                        if(i+1<dominoes.size()&&dominoes[i+1]=='.'){
                            if(i+2<dominoes.size()&&dominoes[i+2]=='L'){
                                L_fall=0;
                            }
                            else{
                                dominoes[i+1]='R';
                                is_change=1;
                                i++;
                            }
                        }
                    }
                }
            }
        }
        return dominoes;
    }
};

class Solution {//一遍版
public:
    string pushDominoes(string dominoes) {
        int last=0;
        int head=1;
        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i]!='.'){
                if(dominoes[i]=='L'){
                    if(head||dominoes[last]=='L'){
                        for(int j=last;j<i;j++){
                            dominoes[j]='L';
                        }
                    }
                    else if(dominoes[last]=='R'){
                        int a=last+1,b=i-1;
                        while(b>a){
                            dominoes[a]='R';
                            dominoes[b]='L';
                            a++;b--;
                        }
                    }
                    last=i;
                }
                else if(dominoes[i]=='R'){
                    if(dominoes[last]=='R'){
                        for(int j=last;j<i;j++){
                            dominoes[j]='R';
                        }
                    }
                    last=i;
                }
                head=0;
            }
        }
        if(dominoes[last]=='R'&&last<dominoes.size()-1){
            for(int i=last;i<dominoes.size();i++){
                dominoes[i]='R';
            }
        }
        return dominoes;
    }
};

//题解1：广度优先搜索，受力叠加分析，倒下的不再受力，
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        queue<int> q;
        vector<int> time(n, - 1);
        vector<string> force(n);
        for (int i = 0; i < n; i++) {
            if (dominoes[i] != '.') {
                q.emplace(i);
                time[i] = 0;
                force[i].push_back(dominoes[i]);
            }
        }
        string res(n, '.');
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (force[i].size() == 1) {
                char f = force[i][0];
                res[i] = f;
                int ni = (f == 'L') ? (i - 1) : (i + 1);
                if (ni >= 0 and ni < n) {
                    int t = time[i];
                    if (time[ni] == -1) {
                        q.emplace(ni);
                        time[ni] = t + 1;
                        force[ni].push_back(f);
                    }
                    else if(time[ni] == t + 1) {
                        force[ni].push_back(f);
                    }
                }
            }
        }
        return res;
    }
};