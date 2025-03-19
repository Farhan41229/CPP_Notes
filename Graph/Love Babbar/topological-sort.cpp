#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj; // Adjacency List
    vector<vector<int>> matrix; // Adjacency Matrix
    int n; // Number of nodes

    Graph(int nodes) {
        n = nodes;
        matrix.resize(n, vector<int>(n, 0));
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

    void printAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // DFS for Topological Sort (Adjacency List)
    void dfs(int node, vector<bool> &visited, stack<int> &st) {
        visited[node] = true;
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, st);
            }
        }
        st.push(node); 
    }

    // Topological Sort using DFS (Adjacency List)
    vector<int> topologicalSort_AdjList() {
        vector<bool> visited(n, false);
        stack<int> st;

        // Ensure all nodes are considered, including isolated ones
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, st);
            }
        }

        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }

    // Topological Sort using DFS (Adjacency Matrix)
    vector<int> topologicalSort_AdjMatrix() {
        vector<bool> visited(n, false);
        stack<int> st;

        function<void(int)> dfsMatrix = [&](int node) {
            visited[node] = true;
            for (int i = 0; i < n; i++) {
                if (matrix[node][i] == 1 && !visited[i]) {
                    dfsMatrix(i);
                }
            }
            st.push(node);
        };

        // Ensure all nodes are considered, including isolated ones
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfsMatrix(i);
            }
        }

        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};

int main() {
    int n, m, choice;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;
    
    Graph g(n);

    cout << "Choose Graph Representation:\n1. Adjacency List\n2. Adjacency Matrix\n";
    cin >> choice;

    cout << "Enter directed edges (u -> v):" << endl;
    for (int i = 0; i < m; i++) {  
        int u, v;
        cin >> u >> v;
        if (choice == 1)
            g.addEdge_AdjList(u, v, 1);
        else
            g.addEdge_AdjMatrix(u, v, 1);
    }

    if (choice == 1)
        g.printAdjList();
    else
        g.printAdjMatrix();

    // Perform Topological Sort based on choice
    vector<int> topoSortResult;
    if (choice == 1) {
        topoSortResult = g.topologicalSort_AdjList();
    } else {
        topoSortResult = g.topologicalSort_AdjMatrix();
    }

    cout << "Topological Sort Order: ";
    for (int node : topoSortResult) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
