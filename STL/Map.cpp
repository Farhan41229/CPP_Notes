#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,8,8,8,8};
    map<int, int> cntr;
    for (auto x: v) cntr[x]++;
    for (auto x: cntr){
        int element = x.first;
        int value = x.second;
        cout<<"Element: "<<element<<" value: "<<value<<endl;
    }
    // cout<<endl;
}