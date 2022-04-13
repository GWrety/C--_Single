#include<bits/stdc++.h>
/*
一开始想的只用hash表.但确实实现不了O（1）随机返回
就必须把数组存下标上返回，hash值存下标位置 删除时把最后一个移动上来，
满足O（1）时间内删除，O（1）时间内访问，O（1）时间内返回
知道下标的情况下，完全可以用vector
尽管已经从题解的角度出发 但对于数组长度和length的关系还是搞混了 WA了4遍
*/
class RandomizedSet {
    vector<int> arr;
    int length=0;
    unordered_map<int,int> Hash;
public:
    RandomizedSet() {
        srand(time(0));
    }
    bool insert(int val) {
        if(Hash.find(val)!=Hash.end()) return false;
        Hash[val]=length;
        if(length<arr.size()){
            arr[length]=val;
        }
        else{
            arr.push_back(val);
        }
        
        length++;
        return true;
    }
    bool remove(int val) {
        if(Hash.find(val)==Hash.end()) return false;
        int pos=Hash[val];
        if(length!=1){
            Hash[arr[length-1]]=pos;
            arr[pos]=arr[length-1];
        }
        length--;
        Hash.erase(val);
        return true;
    }
    int getRandom() {
        return arr[rand()%length];
    }
};
