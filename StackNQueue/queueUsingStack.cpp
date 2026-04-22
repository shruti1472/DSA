#include<iostream>
#include<stack>
using namespace std;

class MyQueue{
    private:
    stack<int>s,s1;

    public:
    MyQueue(){

    }

    void enqueue(int x){
        // if(s.empty()){
        //     s.push(x);
        //     return;
        // }

        // int temp=s.top();
        // s.pop();
        // enqueue(x);
        // s.push(temp);

        //using two stack
        while(!s.empty()){
            s1.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!s1.empty()){
            s.push(s1.top());
            s1.pop();
        }
        
    }

    void dequeue(){
        if(s.empty()){
            cout<<"queue is empty\n";
        }
        else{
            s.pop();
        }
    }

    int frontele(){
          if(s.empty()){
            cout<<"stack is empty\n";
          }
          else{
            return s.top();
          }
    }

    void printQueue(){
        if(s.empty()){
            cout<<"queue is empty\n";
        }
        stack<int> temp=s;
        while(!temp.empty()){
            cout<<temp.top()<<" ";
            temp.pop();
        }
    }
};
int main(){
    MyQueue q;
     q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);


    cout<<"queue looks like\n";
    q.printQueue();

    q.dequeue();
    cout<<"queue looks like\n";
    q.printQueue();


    q.enqueue(50);
    q.enqueue(60);

    cout<<"queue looks like\n";
    q.printQueue();

    q.dequeue();
    cout<<"queue looks like\n";
    q.printQueue();

    q.enqueue(50);
    cout<<"queue looks like\n";
    q.printQueue();

    return 0;
}