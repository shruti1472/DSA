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

//inserting at head O(1) time complexity
Node* insertAtHead(Node* head,int value){
    return new Node(value,head);
    // Node* newNode=new Node(value);
    // newNode->next=head;
    // head=newNode;
    // return head;
    // return newNode;
}

//inserting at tail O(n) time complexity
Node* insertAtEnd(Node* head,int value){
    Node* newNode=new Node(value);
    if(head==nullptr){
        return newNode;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;

}

 Node* insertAtIndex(Node* head,int value,int index){
    if(head==nullptr){
        return head;
    }
    if(index==0){
        return insertAtHead(head,value);
    }
    Node* temp=head;
    int i=0;
    while(temp!=nullptr && i<index-1){
        temp=temp->next;
        i++;
    }
    if(temp==nullptr){
        return head;
    }
    Node* newNode=new Node(value);
    newNode->next=temp->next;
    temp->next=newNode;
    return head;

}

 Node* insertByValue(Node* head,int value,int gvalue){
    if(head==nullptr){
        return head;
    }
    
    Node* temp=head;
    while(temp!=nullptr && temp->data!=gvalue){
        temp=temp->next;
    }
    if(temp==nullptr){
        return head;
    }
    Node* newNode=new Node(value);
    newNode->next=temp->next;
    temp->next=newNode;
    return head;

}

int main(){
    vector<int>arr={1,2,3,4,5,6};
    Node* head=arrtoLL(arr);

    //insertion at head
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

    //insertion at tail
    head=insertAtEnd(head,7);
    cout<<"after insertion at tail: "<<endl;
    temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;

    }
    cout<<endl;

    //insertion at index
    head=insertAtIndex(head,8,3);
    cout<<"after insertion at index 3: "<<endl;
    temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;

    }
    cout<<endl;

    //insertion at index
    head=insertByValue(head,9,8);
    cout<<"after insertion after the value: "<<endl;
    temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;

    }
    cout<<endl;
    return 0;
}

