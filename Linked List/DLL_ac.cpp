#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int val){
            data = val;
            next = NULL;
            prev = NULL;
        }
};

class DLL{
    private:
        Node* head;
        Node* tail;
    public:
        DLL(){
            head = tail = NULL;
        }
        void push_front(int val){
                Node* newnode = new Node(val); // Dynamic and is more preffered than static
                if (head == NULL){
                    head = tail = newnode;
                    return;
                }

                head->prev = newnode;
                newnode->next = head;
                head = newnode;

        }
        void push_back(int val){
                Node* newnode = new Node(val); // Dynamic and is more preffered than static
                if (head == NULL){
                    head = tail = newnode;
                    return;
                }

                tail->next = newnode;
                newnode->prev = tail;
                tail = newnode;

        }

        void insert(int val, int pos){
            if (pos == 0){
                push_front(val);
                return;
            }

            Node* temp = head;
            for (int i = 0; i<pos-1; i++){
                if (temp == NULL){
                    cout<<"Invalid position"<<endl;
                    return;
                }
                temp = temp->next;

            }

            Node* newnode = new Node(val);
            newnode->next = temp->next;
            temp->next->prev = newnode;
            newnode->prev = temp;
            temp->next = newnode;
        }

        void pop_front(){
            if(head == NULL) return;
            Node *temp = head;
            head = head-> next;
            temp->next = NULL;
            if (head != NULL) head->prev = NULL;
            delete temp;
        }

        void pop_back(){
            if (head == NULL) return;
            Node *temp = tail;
            tail = tail-> prev;
            if (tail != NULL) tail->next = NULL;
            temp->prev = NULL;
            delete temp;
        }

        void delete_node(int val){
            if (head == NULL) return;
            if (head-> data == val) pop_front();
            else{
                Node * temp = head;
                Node * temp2 = head;
                while(temp != NULL && temp2->data != val){
                    temp = temp2;
                    temp2 = temp2->next;
                }
                if (temp2 == NULL){
                    cout<<"Invalid Value"<<endl;
                    return;
                }
                else{
                    temp->next = temp2->next;
                    delete temp2;
                }

            }
        }

        int Search(int val){
            Node* temp = head;
            int index = 0;
            while(temp != NULL){
                if (temp->data == val){
                    return index;
                }
                temp = temp->next;
                index++;
            }
            return -1;
        }
        
        void printDLL(){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

int main(){
    DLL l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_back(4);
    l1.printDLL();
    // l1.pop_front();
    // l1.pop_back();
    l1.insert(5, 2);
    l1.printDLL();
    cout<<l1.Search(5)<<endl;
}