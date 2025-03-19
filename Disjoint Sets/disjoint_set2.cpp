/*This is the codes on Disjoint set By LUV without Path Compression and Rank*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int parent[N];


void make(int v){
    parent[v] = v;
}

int find(int v){
    if(v == parent[v]) return v;
    return find(parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        parent[b] = a;
    }

}
 
 

int main(){

}