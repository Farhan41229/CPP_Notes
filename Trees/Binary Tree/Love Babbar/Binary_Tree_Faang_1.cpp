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

Node* buildtree2(Node* root, int n, vector<pair<int, int>>& nodes, vector<int>& queries) {
    // Creating a tree from the input provided in the problem statement
    vector<Node*> tree(n+1, nullptr);
    
    // Building the tree nodes with provided left and right child indices
    for (int i = 1; i <= n; ++i) {
        int a = nodes[i-1].first;
        int b = nodes[i-1].second;
        
        tree[i] = new Node(i);
        if (a != -1) tree[i]->left = tree[a];
        if (b != -1) tree[i]->right = tree[b];
    }
    
    // Performing the swap operations based on queries
    for (int k : queries) {
        Node* temp = tree[k]->left;
        tree[k]->left = tree[k]->right;
        tree[k]->right = temp;
    }

    // Return the root of the tree
    return tree[1];
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

// Problem #01 => https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
// Problem #02 => https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
// Problem #03 => https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1
// Problem #04 => https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
// Problem #05 => https://www.geeksforgeeks.org/problems/sum-tree/1  ** HARD