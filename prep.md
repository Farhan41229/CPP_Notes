<h1 style="text-align: center;">Hashing</h1>

```cpp
#include <iostream>
#define SIZE 10
#define PRIME 7

using namespace std;

class HashTable {
private:
    int H[SIZE] = {0};

    int Hash(int key) {
        return key % SIZE;
    }

    int LinearProbe(int key, int &attempts) {
        int idx = Hash(key);
        int i = 0;
        while (H[(idx + i) % SIZE] != 0) {
            cout << "Collision: Index-" << (idx + i) % SIZE << endl;
            i++;
            attempts++;
            if (attempts >= 6) return -1;
        }
        return (idx + i) % SIZE;
    }

    int QuadraticProbe(int key, int &attempts) {
        int idx = Hash(key);
        int i = 0;
        while (H[(idx + i * i) % SIZE] != 0) {
            cout << "Collision: Index-" << (idx + i * i) % SIZE << endl;
            i++;
            attempts++;
            if (attempts >= 6) return -1;
        }
        return (idx + i * i) % SIZE;
    }

    int PrimeHash(int key) {
        return PRIME - (key % PRIME);
    }

    int DoubleHash(int key, int &attempts) {
        int idx = Hash(key);
        int i = 0;
        while (H[(idx + i * PrimeHash(key)) % SIZE] != 0) {
            cout << "Collision: Index-" << (idx + i * PrimeHash(key)) % SIZE << endl;
            i++;
            attempts++;
            if (attempts >= 6) return -1;
        }
        return (idx + i * PrimeHash(key)) % SIZE;
    }

    float CalculateLoadFactor() {
        int filled = 0;
        for (int i = 0; i < SIZE; i++) {
            if (H[i] != 0) filled++;
        }
        return static_cast<float>(filled) / SIZE;
    }

public:
    void Insert(int key, int choice) {
        int idx, attempts = 0;
        switch (choice) {
            case 1: // Linear Probing
                idx = LinearProbe(key, attempts);
                break;
            case 2: // Quadratic Probing
                idx = QuadraticProbe(key, attempts);
                break;
            case 3: // Double Hashing
                idx = DoubleHash(key, attempts);
                break;
            default:
                cout << "Invalid choice!" << endl;
                return;
        }

        if (idx != -1) {
            H[idx] = key;
            cout << "Inserted : Index-" << idx << " (L.F = " << CalculateLoadFactor() << ")" << endl;
        } else {
            cout << "Input Abandoned" << endl;
        }
    }

    void Print_Table(string s) {
        cout << s << ": [";
        for (int i = 0; i < SIZE; i++) {
            cout << H[i];
            if (i < SIZE - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
};

int main() {
    int choice, n, key;
    cout << "Enter choice (1: Linear, 2: Quadratic, 3: Double): ";
    cin >> choice;
    cout << "Enter number of elements: ";
    cin >> n;

    HashTable ht;
    for (int i = 0; i < n; i++) {
        cout << "Enter key to insert: ";
        cin >> key;
        ht.Insert(key, choice);
    }

    ht.Print_Table("Hash Table");
    return 0;
}

```

<h1 style="text-align: center;">Trie</h1>

```cpp
#include <bits/stdc++.h>
using namespace std;

// Node structure for Trie
struct Node {
    Node* next[26];
    bool endmark;
    int prefixCount;

    Node() {
        endmark = false;
        prefixCount = 0;
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
};

// Trie class
class Trie {
private:
    Node* root;


    void display(Node* curr, string str) {
    if (curr->endmark) {
        cout << str << endl;
    }
    for (int i = 0; i < 26; i++) {
        if (curr->next[i]) {
            display(curr->next[i], str + char('a' + i));
        }
    }
    }


public:

    Trie() {
        root = new Node();
    }


    void insert(string word) {
        Node* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!curr->next[index]) {
                curr->next[index] = new Node();
            }
            curr = curr->next[index];
            curr->prefixCount++;
        }
        curr->endmark = true;
    }


    bool search(string word) {
        Node* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!curr->next[index]) {
                return false;
            }
            curr = curr->next[index];
        }
        return curr->endmark;
    }


    bool startsWith(string prefix) {
        Node* curr = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!curr->next[index]) {
                return false;
            }
            curr = curr->next[index];
        }
        return true;
    }

    int countWordsWithPrefix(string prefix) {
        Node* curr = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!curr->next[index]) {
                return 0;
            }
            curr = curr->next[index];
        }
        return curr->prefixCount;
    }




    void displayAll() {
    display(root, "");
}

};

int main() {
    Trie trie;

    vector<string> words;
    int wordscount, queries;
    cout<<"Enter the number of words and the number of queries!!! "<< endl;
    cin >> wordscount >> queries;
    cout<<"Now, enter the words !!!"<< endl;
    for (int i=0; i<wordscount; i++){
        string s;
        cin>>s;
        words.push_back(s);
    }
    for (auto elem : words) trie.insert(elem);
    cout<<"Displaying the Trie"<<endl;
    trie.displayAll();

    cout<<"Now enter the queries"<<endl;
    for(int i=0; i<queries; i++){
        string s;
        cin>>s;
        cout << (trie.search(s) ? "T" : "F") << endl;
    }

    return 0;
}
```

<h2 style="text-align: center;">TRIE XOR</h1>

```cpp
#include <bits/stdc++.h>
    using namespace std;

    // Node structure for Trie
    struct Node {
        Node* next[2];
        bool endmark;
        int prefixCount;

        Node() {
            endmark = false;
            prefixCount = 0;
            for (int i = 0; i < 2; i++) {
                next[i] = nullptr;
            }
        }
    };


    class Trie {
    private:
        Node* root;

    public:
        Trie()  { root = new Node(); }

        void insert(int n) {
            Node* curr = root;
            for (int i = 31; i>=0; i--) {
                int index = (n>>i) & 1;
                if (!curr->next[index]) {
                    curr->next[index] = new Node();
                }
                curr = curr->next[index];
                curr->prefixCount++;
            }
            curr->endmark = true;
        }

        int getmax(int value){
            Node * curr = root;
            int answer = 0;

            for (int i = 31; i>=0; i--) {
                int index = (value>>i) & 1;
                if (curr->next[1 - index]) {
                answer |= (1 << i);
                curr = curr->next[1 - index];
                } else {
                curr = curr->next[index];
                }
            }
            return answer;
        }

        int max_xor(int arr[], int size){
            int max_value = 0;
            insert(arr[0]);
            for (int i= 1; i<size;i++){
                max_value = max(getmax(arr[i]), max_value);
                insert(arr[i]);
            }
            return max_value;
        }
    };

    int main() {
        Trie trie;
        int n;
        cin>>n;
        int array[n];
        for (int i = 0; i<n; i++) cin>>array[i];
        cout<<trie.max_xor(array, n)<<endl;



        return 0;
    }
```

<h1 style="text-align: center;">DSU</h1>

```cpp
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
        // else return FindParent(parent[node]);
        return parent[node] = FindParent(parent[node]); // Path compression
    }

    void Union(int a, int b){
        a = FindParent(a);
        b = FindParent(b);
        if(a != b){
            parent[b] = a;
        }

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
            parent[pu] = pv;
            rank[pv]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = FindParent(u);
        int ulp_v = FindParent(v);
        if (ulp_u == ulp_v) return; // Already in the same set

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    void PrintDS1() {
        unordered_map<int, vector<int>> groups;
        for (int i = 1; i < parent.size(); i++) {
            groups[FindParent(i)].push_back(i);
        }

        // cout << "\n================================\n";
        // cout << "      DISJOINT SET STRUCTURE    \n";
        // cout << "================================\n";
        // cout << setw(10) << "Leader" << " | " << "Elements in the Set\n";
        // cout << "--------------------------------\n";

        // for (auto &group : groups) {
        //     cout << setw(8) << group.first << "  | { ";
        //     for (size_t i = 0; i < group.second.size(); i++) {
        //         cout << group.second[i];
        //         if (i != group.second.size() - 1) cout << ", ";
        //     }
        //     cout << " }\n";
        // }

        // cout << "================================\n";
        cout<<"Printing the Groups sizes..."<<groups.size()<<endl;
        int ans = INT_MIN;
        for (auto &group : groups) {
            int size = group.second.size();
            ans = max(ans, size);
        }
        cout<<"Max Size: "<<ans<<endl;

    }
    void PrintDS2() {
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
    // DisjointSet ds(7);
    // ds.unionBySize(1, 2);
    // ds.unionBySize(2, 3);
    // ds.unionBySize(4, 5);
    // ds.unionBySize(6, 7);
    // ds.unionBySize(5, 6);

    // cout << "Before Union(3,7):";
    // ds.PrintDS();

    // if (ds.FindParent(3) == ds.FindParent(7)) {
    //     cout << "Same\n";
    // } else {
    //     ds.unionBySize(3, 7);
    // }

    // cout << "\nAfter Union(3,7):";
    // ds.PrintDS();

    int n,commands=0;
    cin >> n;
    int q;
    cin >> q;
    DisjointSet ds(n);
    while (q--) {
            int a,b;
            cin>>a;
            cin>>b;
            ds.UnionByRank(a,b);
            ds.PrintDS1();

    }

    return 0;
}

```

<h1 style="text-align: center;">Graph Theory</h1>

```cpp
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

/*
GIT CLONE =>
git clone https://github.com/Farhan41229/CPP_Notes.git
*/
```

<h1 style="text-align: center;">Tree</h1>

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildtree(Node* root){
    cout<<"Enter the Data: ";
    int data;
    cin >> data;
    root = new Node(data);


    if (data == -1) return nullptr;

    cout<<"Insert Data for inserting into the left of "<<data<<endl;
    root->left = buildtree(root->left);
    cout<<"Insert Data for inserting into the right of "<<data<<endl;
    root->right = buildtree(root->right);
    return root;

}
int height(Node* node){
    if (node == nullptr) return 0;
    else return 1 + max(height(node->left) , height (node->right));
}

bool isBalanced(Node* root) {
        // Code here
        if (root == NULL ) return true;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool diff = abs(height(root->left) - height(root->right)) <= 1;
        if (left and right and diff) return true;
        else return false;
}

pair<int,int> Diameter_Fast(Node* root){
        if (root == NULL){
            pair<int, int> p = make_pair(0,0);
            return p;
        }

        pair<int, int> left = Diameter_Fast(root->left);
        pair<int, int> right =  Diameter_Fast(root->right);

        int a = left.first;
        int b = right.first;
        int c = left.second + right.second;
        pair <int,int> ans;
        ans.first = max(a, max(b,c));
        ans.second = max(left.second, right.second) + 1;
        return ans;
    }
    int diameter(Node* root) {
        // Your code here
        return Diameter_Fast(root).first;
}

pair<bool, int> IsSumTreeFast(Node* root){
        if (root == NULL){
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }
        if (root->left == NULL and root->right == NULL){
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }
        pair<bool, int> leftAns = IsSumTreeFast(root->left);
        pair<bool, int> rightAns = IsSumTreeFast(root->right);

        bool left = leftAns.first;
        bool right = rightAns.first;

        bool condition = root->data == (leftAns.second + rightAns.second);

        pair<bool, int> ans;
        if (left and right and condition) ans.first = true;
        else ans.first = false;
        ans.second = root->data + leftAns.second + rightAns.second;
        return ans;

    }

    bool isSumTree(Node* root) {
        // Your code here
        pair<bool, int> ans = IsSumTreeFast(root);
        return ans.first;
}

bool isIdentical(Node *r1, Node *r2) {
        // Your Code here
        if (r1 == NULL and r2 == NULL ) return true;
        if (r1 == NULL and r2 != NULL ) return false;
        if (r1 != NULL and r2 == NULL) return false;
        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        bool val = r1->data == r2->data;
        if (left and right and val) return true;
        else return false;
}

void LevelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) // Completed Level Traversal
        {
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp -> left) q.push(temp->left);
            if(temp -> right) q.push(temp -> right);
        }


    }
}
void InorderTraversal(Node* root){
    // Base Case
    if (root == NULL) return;
    // Other Cases
    InorderTraversal(root -> left);
    cout<<root->data<<" ";
    InorderTraversal (root -> right);
}
void PreOrderTraversal (Node * root){
    // Base Case
    if (root == NULL) return;
    // Other Cases
    cout<<root->data<<" ";
    PreOrderTraversal(root -> left);
    PreOrderTraversal (root -> right);
}
void PostOrderTraversal (Node * root){
    // Base Case
    if (root == NULL) return;
    // Other Cases
    PostOrderTraversal(root -> left);
    PostOrderTraversal (root -> right);
    cout<<root->data<<" ";
}

void BuildFromLevelOrder(Node*& root) {
    queue<Node*> q;
    cout << "Enter Data for the root node: ";
    int data;
    cin >> data;

    if (data == -1) {
        root = nullptr;
        return;
    }

    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Insert Left Node
        cout << "Enter Left Node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        // Insert Right Node
        cout << "Enter Right Node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}


int main(){
    Node* root = NULL;

    // Creating a tree
    root = buildtree(root);
    // Showcasing the Height Function
    // int root_height = height(root);
    // cout<<root_height<<endl;

}

```

<h1 style="text-align: center;">Segment Tree</h1>

```cpp
// This is the implementation of the segment Trees based on the Udemy Course Competitive Programming Essentials, Master Algorithms. This code
// contains most of the necessary implementation of the segment tree... */

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using grid = vector<vi>;
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
#define en "\n"
#define ln " \n"[i==n-1]
#define sz(_O) _O.size()
#define fix(_O) cout<<setprecision(_O)<<fixed
#define fir(_O) for(int i=0, ii=_O-1; i<_O; ++i, --ii)
#define fjr(_O) for(int j=0, jj=_O-1; j<_O; ++j, --jj)
ll const inf = 1e18; //0x3f3f3f3f3f3f;
ll const mod = 1e9+7; //998244353;

struct segmenttree {
	int n;
	vector<int> st;

	void init(int _n) {
		this->n = _n;
		st.resize(4 * n, 0);
	}

	void build(int start, int ending, int node, vector<int> &v) {
		// leaf node base case
		if (start == ending) {
			st[node] = v[start];
			return;
		}

		int mid = (start + ending) / 2;

		// left subtree is (start,mid)
		build(start, mid, 2 * node + 1, v);

		// right subtree is (mid+1,ending)
		build(mid + 1, ending, 2 * node + 2, v);

		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
	}

	int query(int start, int ending, int l, int r, int node) {
		// non overlapping case
		if (start > r || ending < l) {
			return 0;
		}

		// complete overlap
		if (start >= l && ending <= r) {
			return st[node];
		}

		// partial case
		int mid = (start + ending) / 2;

		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

		return q1 + q2;
	}

	void update(int start, int ending, int node, int index, int value) {
		// base case
		if (start == ending) {
			st[node] = value;
			return;
		}

		int mid = (start + ending) / 2;
		if (index <= mid) {
			// left subtree
			update(start, mid, 2 * node + 1, index, value);
		}
		else {
			// right
			update(mid + 1, ending, 2 * node + 2, index, value);
		}

		st[node] = st[node * 2 + 1] + st[node * 2 + 2];

		return;
	}

	void build(vector<int> &v) {
		build(0, n - 1, 0, v);
	}

	int query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}

	void update(int x, int y) {
		update(0, n - 1, 0, x, y);
	}
    void print_tree() {
        int level = 0, nodes_in_level = 1, index = 0;
        int max_width = 4 * n;  // Maximum possible nodes in the segment tree

        cout << "Segment Tree Structure:\n";

        while (index < 4 * n) {
            int spaces = max_width / (nodes_in_level + 1);  // Adjust spacing per level

            for (int i = 0; i < nodes_in_level && index < 4 * n; ++i, ++index) {
                cout << string(spaces, ' ');  // Print leading spaces
                if (st[index] != 0) cout << st[index];
                else cout << "_";
            }
            cout << "\n";
            nodes_in_level *= 2;  // Move to the next level
        }
    }


};

void process_case() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    segmenttree tree;
    tree.init(v.size());
    tree.build(v);
    tree.print_tree();

}

int main() {
    ios::sync_with_stdio(false);
#ifndef FARHAN_TAHSIN
    cin.tie(nullptr);
#endif

    int test_cases = 1;
    // cin >> test_cases;

    while (test_cases-- > 0)
        process_case();
}




```

<h1 style="text-align: center;">Sparse Table</h1>

```cpp
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SparseTable {
private:
    vector<vector<int>> table; // 2D Array of Table to store the precomputed numbers...
    vector<int> logValues;
    int n;

public:
    SparseTable(const vector<int>& arr) {
        n = arr.size();
        int maxLog = log2(n) + 1;
        table.assign(n, vector<int>(maxLog));

        // Initializing the first column to sotre the initial values
        for (int i = 0; i < n; i++)
            table[i][0] = arr[i];

        // Computing the values for all intervals to be used
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; (i + (1 << j) - 1) < n; i++) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }


        logValues.resize(n + 1);
        logValues[1] = 0;
        for (int i = 2; i <= n; i++)
            logValues[i] = logValues[i / 2] + 1;
    }

    // Query for range minimum
    int query(int L, int R) {
        int j = logValues[R - L + 1];
        return min(table[L][j], table[R - (1 << j) + 1][j]);
    }

    void printTable() {
        cout << "Status of Sparse Table:\n";
        for (const auto& row : table) {
            for (int val : row)
                cout << val << " ";
            cout << "\n";
        }
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    SparseTable st(arr);

    int Q;
    cin >> Q;

    cout << "Ranges to be stored in Sparse Table:\n";
    for (int i = 0; (1 << i) <= N; i++) {
        for (int j = 0; j + (1 << i) - 1 < N; j++) {
            cout << "(" << j << "," << j + (1 << i) - 1 << ") ";
        }
        cout << "\n";
    }

    st.printTable();

    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        cout << "Query-" << i + 1 << ": Min=" << st.query(L, R) << "\n";
    }

    return 0;
}

```
