#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) { // Fix loop boundary
            parent[i] = i;
        }
    }

    int FindParent(int node) {
        if (node == parent[node]) return node;
        else return FindParent(parent[node]);
        // return parent[node] = FindParent(parent[node]); // Path compression
    }

    void UnionByRank(int u, int v) {
        int pu = FindParent(u);
        int pv = FindParent(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = FindParent(u); // Find ultimate parent of u
        int ulp_v = FindParent(v); // Find ultimate parent of v

        if (ulp_u == ulp_v) return; // Already in the same set

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    void PrintDS() {
    unordered_map<int, vector<int>> groups;
    for (int i = 1; i < parent.size(); i++) {
        groups[FindParent(i)].push_back(i);
    }

    cout << "\n================================\n";
    cout << "      DISJOINT SET STRUCTURE    \n";
    cout << "================================\n";
    cout << setw(10) << "Leader" << " | " << "Elements in the Set\n";
    cout << "--------------------------------\n";

    for (auto &group : groups) {
        cout << setw(8) << group.first << "  | { ";
        for (size_t i = 0; i < group.second.size(); i++) {
            cout << group.second[i];
            if (i != group.second.size() - 1) cout << ", ";
        }
        cout << " }\n";
    }

    cout << "================================\n";
}

};

int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    
    cout << "Before Union(3,7):";
    ds.PrintDS();

    if (ds.FindParent(3) == ds.FindParent(7)) {
        cout << "Same\n";
    } else {
        ds.unionBySize(3, 7);
    }

    cout << "\nAfter Union(3,7):";
    ds.PrintDS();

    return 0;
}
