#include<bits/stdc++.h>
//22.4.23
/*
用了常规思路去想  但确实不太好做
看题解  这是一个凸包问题的板子题    有多种解法  
*/
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n=trees.size();
        if(n==1) return trees;
        vector<vector<int>> ans;
        vector<vector<int>> left,right,up,down;
        left.push_back(trees[0]);
        right.push_back(trees[0]);
        up.push_back(trees[0]);
        down.push_back(trees[0]);
        for(auto i:trees){
            if(i==left[0]) continue;
            if(i[0]<=left[0][0]){
                if(i[0]==left[0][0]){
                    left.push_back(i);
                }
                else{
                    left.clear();
                    left.push_back(i);
                }
            }
            if(i[0]>=right[0][0]){
                if(i[0]==right[0][0]){
                    right.push_back(i);
                }
                else{
                    right.clear();
                    right.push_back(i);
                }
            }
            if(i[1]<=down[0][1]){
                if(i[1]==down[0][1]){
                    down.push_back(i);
                }
                else{
                    down.clear();
                    down.push_back(i);
                }
            }
            if(i[1]>=up[0][1]){
                if(i[1]==up[0][1]){
                    up.push_back(i);
                }
                else{
                    up.clear();
                    up.push_back(i);
                }
            }
        }
        int left1x=left[0][0],left1y=left[0][1];
        int left2x=left[0][0],left2y=left[0][1];
        int up1x=up[0][0],up1y=up[0][1];
        int up2x=up[0][0],up2y=up[0][1];
        int down1x=down[0][0],down1y=down[0][1];
        int down2x=down[0][0],down2y=down[0][1];
        int right1x=right[0][0],right1y=right[0][1];
        int right2x=right[0][0],right2y=right[0][1];

        for(auto i:left){
            left1y=max(i[1],left1y);
            left2y=min(i[1],left2y);
        }
        for(auto i:up){
            up1x=max(i[0],up1x);
            up2x=min(i[0],up2x);
        }
        for(auto i:right){
            right1y=max(i[0],right1y);
            right2y=min(i[0],right2y);
        }
        for(auto i:down){
            down1x=max(i[0],down1x);
            down2x=min(i[0],down2x);
        }
        /*
                up2    up1
        left1               right1
        left2               right2
                down2  down1
        */
        vector<pair<int,int>> temp1;
        for(auto i:trees){
            if(i[0]>left1x&&i[0]<up2x&&i[1]>left1y){
                temp1.push_back(make_pair(i[0],i[1]));
            }
        }
        sort(temp1.begin(),temp1.end());
        for(auto i:temp1){
            double k1=(i.second-left1y)/(i.first-left1x);
            double k2=(up2y-left1y)/(up2x-left1x);
            if(k1=k2){

            }
            else if(k1>k2){

            }
        }
        
        for(auto i:left){
            ans.push_back(i);
        }
        for(auto i:up){
            ans.push_back(i);
        }
        for(auto i:right){
            ans.push_back(i);
        }
        for(auto i:down){
            ans.push_back(i);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        if(n <= 3) return trees;

        vector<vector<int>> ans;

        int fir = -1;       //找最左当中最下点作为起始点
        for(int i = 0; i < n; ++i){
            if(fir == -1 || trees[fir][0] > trees[i][0] || (trees[fir][0] == trees[i][0] && trees[fir][1] > trees[i][1])) fir = i;
        }

        int start = fir;
        int sec = -1;

        vector<int> vis(n);

        while(sec != start){
            //find sec
            sec = (fir + 1) % n;
            for(int i = 0; i < n; ++i){
                if(get_angle(trees[fir], trees[sec], trees[i]) < 0) sec = i;
            }
            vis[sec] = 1;
            //cout << fir << " " << sec << endl;
            //if same
            vector<pair<int, int>> same = {{get_dis(trees[fir], trees[sec]), sec}};//记录相同线段上所有点与起始点距离
            for(int i = 0; i < n; ++i){
                if(vis[i] || i == fir || i == sec) continue;

                if(get_angle(trees[fir], trees[sec], trees[i]) == 0){
                    same.push_back({get_dis(trees[fir], trees[i]), i});
                    vis[i] = 1;
                } 
            }

            sort(same.begin(), same.end());

            for(auto& [_, idx] : same){
                ans.push_back(trees[idx]);
                sec = idx;
            }

            fir = sec;
        }

        return ans;
    }

    int get_angle(vector<int>& a, vector<int>& b, vector<int>& c){
        return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]);
    }

    int get_dis(vector<int>& a, vector<int>& b){
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
};