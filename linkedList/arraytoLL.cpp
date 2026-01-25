#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    public:
    Node(int data1,Node* next1){
        this->data=data1;
        this->next=next1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

 Node* arrtoLL(vector<int>arr){
        Node* head=new Node(arr[0]);
        Node* mover=head;
        for(int i=1;i<arr.size();i++){
            Node* temp=new Node(arr[i]);
            mover->next=temp;
            mover=temp;
        }

        return head;
    }

    int Search(Node* head,int key){
        Node* temp=head;
        while(temp!=nullptr){
            if(temp->data==key){
                return 1;
            }
            temp=temp->next;
        }
        return 0;
    }

int main(){
    vector<int>arr={1,2,3,4,5,6};
    Node* head= arrtoLL(arr);
    Node* temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
        cnt++;
    }
    cout<<"NULL"<<endl;
    cout<<"Length of linked list is: "<<cnt<<endl;    //for length of the linked list

    //searching for an element
    int key;
    cout<<"enter the key you want to search: ";
    cin>>key;
    if(Search(head,key)){
      cout<<"element is there\n";
    }
    else{
        cout<<"element is not there\n";
    }
    return 0;
}