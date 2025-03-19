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
    cout<<"Enter the Data: "<<endl;
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
    // BuildFromLevelOrder(root);
    
    // Level Order Traversal
    cout<<"Printing the Level Order Tranversal"<<endl;
    LevelOrderTraversal(root);
    
    // Inorder Traversal
    cout<<"Printing the Inorder Traversal"<<endl;
    InorderTraversal(root);
    cout<<endl;
    
    // PreOrder Traversal
    cout<<"Printing the PreOrder Traversal"<<endl;
    PreOrderTraversal(root);
    cout<<endl;
    
    // PostOrder Traversal
    cout<<"Printing the PostOrder Traversal"<<endl;
    PostOrderTraversal(root);
    cout<<endl;
    

    // Link to the Lecture Problem: https://www.naukri.com/code360/problems/count-leaf-nodes_893055?leftPanelTabValue=SUBMISSION
}

// Test Inputs
// BuildORder = 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1