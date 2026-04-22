#include<iostream>
using namespace std;

class Queue{
    public:
    int q[5];
    int front=-1;
    int rear=-1;

    bool isFull(){
        return((front==0 && rear==4) || (rear==(front-1+5)%5) );
    }

    bool isEmpty(){
        return front==-1;
    }

    void enqueue(int data){
        if(!isFull()){
            if(isEmpty()){
                front=rear=0;
            }
            else{
                rear=(rear+1)%5;
            }
            q[rear]=data;
        }
        else{
            cout<<"queue is full\n";
        }
    }

    void dequeue(){
        if(!isEmpty()){
            if(front==rear){
                front=-1;
                rear=-1;
            }
            else{
                front=(front+1)%5;
            }
        }
        else{
            cout<<"queue is empty\n";
        }
    }

    void printQueue(){
        if(!isEmpty()){
            int i=front;
            while(true){
                cout<<q[i]<<" ";
                if(i==rear) break;
                i=(i+1)%5;
            }
            cout<<endl;
        }
        else{
            cout<<"queue is empty\n";
        }
    }
};

int main(){
    Queue q;
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