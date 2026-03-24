#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }

    Node(int data1,Node* next1,Node* prev1){
        this->data=data1;
        this->next=next1;
        this->prev=prev1;
    }
};

Node* arrtoDLL(vector<int>arr){
    Node* head= new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        temp->next=newNode;
        newNode->prev=temp;
        temp=newNode;
    }
    return head;
}

int main(){
    vector<int>arr={1,2,3,4,5,6};
    Node* head = arrtoDLL(arr);
    Node* temp=head;

    while(temp!=nullptr){
        cout<<temp->data<<"->";
        cout<<temp->prev<<"<(prev)  ";
        cout<<temp->next<<"(next)";
        cout<<endl;
        temp=temp->next;
    }
}