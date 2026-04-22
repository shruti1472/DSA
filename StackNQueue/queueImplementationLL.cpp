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

class Queue{
    public:
    Node* front;
    Node* rear;

    Queue(){
        front=rear=nullptr;
    }

    bool isEmpty(){
        return front==nullptr;
    }

    void enqueue(int data){
        Node* newNode=new Node(data);
        if(isEmpty()){
            front=rear=newNode;
        }
        else{
        rear->next=newNode;
        rear=newNode;
        }
    }

   void dequeue(){
        Node* temp=front;
        front=front->next;
        delete temp;
   

        if(front==nullptr){
        rear=nullptr;
        }
    }

    int frontele(){
        if(isEmpty()){
            cout<<"queue is empty\n";
            return -1;
        }
        else{
            return front->data;
        }
    }

    void printQueue(){
        if(isEmpty()){
            cout<<"queue is empty\n";
        }
        else{
            Node* temp=front;
            while(temp!=nullptr){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
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
