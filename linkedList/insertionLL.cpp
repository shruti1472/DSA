#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }

    public:
    Node(int data1,Node* next1){
        this->data=data1;
        this->next=next1;
    }
};

Node* arrtoLL(vector<int>arr){
        Node* head=new Node(arr[0]);
        Node* temp=head;
        for(int i=1;i<arr.size();i++){
            Node* newNode=new Node(arr[i]);
            temp->next=newNode;
            temp=newNode;
        }
        return head;
}

//inserting at head
Node* insertAtHead(Node* head,int value){
    Node* newNode=new Node(value);
    newNode->next=head;
    head=newNode;
    return head;
}
int main(){
    vector<int>arr={1,2,3,4,5,6};
    Node* head=arrtoLL(arr);
    Node* temp=head;
    cout<<"before insertion at head: "<<endl;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
    head=insertAtHead(head,0);
    cout<<"after insertion at head: "<<endl;
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}

