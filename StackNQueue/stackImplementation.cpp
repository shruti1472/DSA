#include<iostream>
using namespace std;

class Stack{
    public:
    int st[10];
    int top=-1;

    bool isFull(){
        return top==9;
    }

    bool isEmpty(){
        return top==-1;
    }

    void push(int data){
        if(!isFull()){
            top++;
            st[top]=data;
        }
        else{
            cout<<"stack is full"<<endl;
        }
    }

    void pop(){
        if(!isEmpty()){
            top--;
        }else{
            cout<<"stack is empty"<<endl;
        }
    }

    int topEle(){
        if(!isEmpty()){
            cout<<st[top]<<endl;
        }else{
            cout<<"stack is empty"<<endl;
        }
    }

    void printStack(){
        if(!isEmpty()){
            for(int i=top;i>=0;i--){
                cout<<st[i]<<endl;
            }
        }else{
            cout<<"stack is empty"<<endl;
        }
    }
};

int main(){
    Stack s;
    s.push(10); 
    s.push(20);
    s.push(30);
    s.printStack();
    s.pop();
    cout<<"after pop"<<endl;
    s.printStack();
    cout<<"top element is: ";
    s.topEle();
    cout<<"is stack empty? "<<
    s.isEmpty();
    s.push(40);
    s.push(50);
    cout<<"after pushing 40 and 50"<<endl;
    s.printStack();
    s.pop();
    cout<<"after pop"<<endl;
    s.printStack();
    cout<<"top element is: ";
    s.topEle();
}