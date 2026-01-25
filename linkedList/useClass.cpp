#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
         Node* next;
    public:
    Node(int data,Node* next1){
        this->data=data;
        this->next=next1;
    }

    public:
    Node(int data1){
       data=data1;
       next=nullptr;
    }
    
};

int main(){
    vector<int>arr={1,2,3,4,5};
    Node* head=new Node(arr[0]);
    Node* second=new Node(arr[1]);
    head->next=second;
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}