#include<iostream>
#include<queue>
#include<utility>
using namespace std;

class MyStack{
    private:
    queue<int>q,q1;   //using two queue

    public:
    MyStack(){

    }

    void push(int x){
        // q.push(x);
        // int size=q.size();
        // for(int i=1;i<size;i++){
        //     q.push(q.front());
        //     q.pop();
        // }

        //using two queue
        q1.push(x);
        int size=q.size();
       while(!q.empty()){
             q1.push(q.front());
             q.pop();
        }
        swap(q,q1);
    }

    int pop(){
        if(q.empty()){
            return -1;
        }
        int data=q.front();
        q.pop();
        return data;
    }

    int topele(){
        if(q.empty()){
            return -1;
        }
        else{
            return q.front();
        }
    }

    void printStack(){
    if(q.empty()){
        cout << "queue is empty\n";
        return;
    }

    queue<int> temp = q;

    while(!temp.empty()){
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    }
};

int main(){
    MyStack s;
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