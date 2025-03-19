#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    map<int, list<int>> adj; // Adjacency List
    vector<vector<int>> matrix; // Adjacency Matrix
    int n; // Number of nodes

    Graph(int nodes) {
        n = nodes;
        matrix.resize(n, vector<int>(n, 0)); // 0 based indexing
        // matrix.resize(n+1, vector<int>(n+1, 0)); // 1 based indexing
    }

    void addEdge_AdjList(int u, int v, bool direction) {
        adj[u].push_back(v);
        if (!direction) adj[v].push_back(u);
    }

    void addEdge_AdjMatrix(int u, int v, bool direction) {
        matrix[u][v] = 1;
        if (!direction) matrix[v][u] = 1;
    }

    void printAdjList() {
        cout << "Adjacency List:" << endl;
        for (auto &node : adj) {
            cout << node.first << " -> ";
            for (auto &neighbor : node.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void printAdjMatrix() { // Convert the loop from 1 to equal to n for 1 based indexing
        cout << "Adjacency Matrix:" << endl;  // loop from 1 to n-1 for 1 based indexing
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    

    
};

int main() {
    int n, m, choice;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;
    
    Graph g(n);

    cout << "Choose Graph Representation:\n1. Adjacency List\n2. Adjacency Matrix\n";
    cin >> choice;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {  
        int u, v;
        cin >> u >> v;
        if (choice == 1)
            g.addEdge_AdjList(u, v, 0);
        else
            g.addEdge_AdjMatrix(u, v, 0);
    }

    if (choice == 1)
        g.printAdjList();
    else
        g.printAdjMatrix();

    

    return 0;
}
