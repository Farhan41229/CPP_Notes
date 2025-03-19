#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
};

class List{
    private:
        Node* head;
        Node* tail;
    public:
        List(){
            head = tail = NULL;
        }
        void push_front(int val){
                Node* newnode = new Node(val); // Dynamic and is more preffered than static
                if (head == NULL){
                    head = tail = newnode;
                    return;
                }

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
            temp->next = newnode;
        }

        void pop_front(){
            if(head == NULL) return;
            Node *temp = head;
            head = head-> next;
            temp->next = NULL;
            delete temp;
        }

        void pop_back(){
            if (head == NULL) return;
            Node *temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
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
        
        void printLL(){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};


int main(){
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.push_back(4);
    ll.push_back(5);
    ll.delete_node(1);
    ll.printLL();

    ll.pop_front();

    ll.pop_back();


    List ll2;
    ll2.push_front(3);
    ll2.push_front(2);
    ll2.push_front(1);
    ll2.insert(4, 1);
    ll2.printLL();
    cout<<ll2.Search(3)<<endl;

}