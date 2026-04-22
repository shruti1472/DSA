#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1){
         data=data1;
         next=nullptr;
    }

    Node(int data1,Node* next1){
        this->data=data1;
        this->next=next1;
    }
};

class Stack{
    public:
    Node* top;
   
    Stack(){
        top=nullptr;
    }

    bool isEmpty(){
        return top==nullptr;
    }

    void push(int data){
        Node* newnode=new Node(data);
        newnode->next=top;
        top=newnode;
    }

    void pop(){
        if(isEmpty()){
            cout<<"stack is empty\n";
        }
        else{
            Node* temp=top;
            top=top->next;
            delete temp;
        }
    }

    int topele(){
        if(isEmpty()){
            cout<<"stack is empty\n";
        }
        else{
            return top->data;
        }
    }
   
    void printStack(){
        if(isEmpty()){
            cout<<"stack is empty\n";
        }
        else{
            Node* temp=top;
            while(temp!=nullptr){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<"stack now is\n";
    s.printStack();
    cout<<"top element of stack is :"<<s.topele()<<endl;
    s.pop();
    s.pop();
    cout<<"stack now is\n";
    s.printStack();
    s.push(40);
    s.push(50);
    cout<<"stack now is\n";
    s.printStack();

}