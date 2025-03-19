#include<bits/stdc++.h>
using namespace std;

// Function to print the stack
void printStack( stack<int> s1){
    while(! s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }
}

bool isFull(stack<int> s1, int size){
    if (s1.size()==size) return true;
    else return false;
}

int main(){

    // STACK STL NOTES
    // Declaration, push and pop
    stack<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    printStack(s1);

    s1.pop();
    s1.pop();
    printStack(s1);

    // Check whether stack is empty or full
    (s1.empty()) ? cout<<"Stack is empty"<<endl : cout<<"Stack is not empty"<<endl;
    (isFull(s1, 5)) ? cout<<"Stack is Full"<<endl : cout<<"Stack is not full"<<endl;

    // Swapping Stacks
    stack<int> s2;
    s2.push(1);
    s2.push(3);
    s2.push(2);

    s1.swap(s2);
    cout<<"Printing s1"<<endl;
    printStack(s1);
    cout<<"Printing s2"<<endl;
    printStack(s2);
}