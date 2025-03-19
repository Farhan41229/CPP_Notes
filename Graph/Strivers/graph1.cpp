/*This is the code on GRAPHS from Strivers. G-2 Graph Representation in C++ */


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    // /*Adjajency Matrix*/
    // int adj[n+1][m+1]; // This is for 1 based indexing. For 0 base, just keep n and m.
    // for(int i = 0; i <m; i++){
    //     int u,v;
    //     cin >> u >> v;
    //     adj[u][v] = 1;
    //     adj[v][u] = 1;
    // }
    /* Adjajency list*/
    vector<int> adj[n+1];
    for(int i = 0; i <m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // This will be removed for the directed graph
    }
    return 0;
}