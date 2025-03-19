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

    bool BFS_PathCheck(int src, int dest) {
        queue<int> q;
        unordered_set<int> visited;

        q.push(src);
        visited.insert(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dest) return true; // If the destination is found, return true

            for (int neighbor : adj[node]) { // Explore neighbors
                if (visited.find(neighbor) == visited.end()) { // If not visited
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return false; // If the destination is not reachable
    }

    // Function to perform BFS traversal starting from a given node
    vector<int> BFS(int start) {
        vector<int> bfs_result; // Vector to store BFS traversal
        unordered_set<int> visited; // Set to keep track of visited nodes
        queue<int> q; // Queue to manage the BFS process

        q.push(start); // Start BFS from the given node
        visited.insert(start);

        while (!q.empty()) {
            int node = q.front(); // Get the front node of the queue
            q.pop();
            bfs_result.push_back(node); // Add it to the BFS result

            // Explore all neighbors of the current node
            for (int neighbor : adj[node]) {
                if (visited.find(neighbor) == visited.end()) { // If not visited
                    visited.insert(neighbor); // Mark as visited
                    q.push(neighbor); // Add to the queue for further exploration
                }
            }
        }

        return bfs_result; // Return the BFS traversal result
    }

    // Function to perform DFS traversal starting from a given node
    void DFS(int node, unordered_set<int> &visited, vector<int> &dfs_result) {
        visited.insert(node); // Mark the current node as visited
        dfs_result.push_back(node); // Add it to the DFS result

        // Explore all neighbors of the current node
        for (int neighbor : adj[node]) {
            if (visited.find(neighbor) == visited.end()) { // If not visited
                DFS(neighbor, visited, dfs_result); // Recursively perform DFS on the neighbor
            }
        }
    }

    // Wrapper function to call DFS and return the DFS result
    vector<int> DFS(int start) {
        vector<int> dfs_result; // Vector to store DFS traversal
        unordered_set<int> visited; // Set to keep track of visited nodes

        DFS(start, visited, dfs_result); // Perform DFS starting from the given node

        return dfs_result; // Return the DFS traversal result
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

    // Perform BFS traversal from node 0 and print the result
    vector<int> bfs_result = g.BFS(2);  // Start BFS from node 0
    cout << "BFS Traversal starting from node 0: ";
    for (int node : bfs_result) {
        cout << node << " ";
    }
    cout << endl;

    // Perform DFS traversal from node 0 and print the result
    vector<int> dfs_result = g.DFS(2);  // Start DFS from node 0
    cout << "DFS Traversal starting from node 0: ";
    for (int node : dfs_result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

/*
// Test inputs
5 4 1
0 3
1 2
1 3
1 4
*/

// Problem Links
/*
Problem #01 => https://www.naukri.com/code360/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&problemListRedirection=true&practice_topic%5B%5D=Graph&leftPanelTabValue=SUBMISSION
*/
