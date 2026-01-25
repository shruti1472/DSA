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

//deleting head node
    Node* deletionHead(Node* head){
        if(head ==nullptr){
            return head;
        }
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }

//deleting node at given index
     Node* deletionAtIndex(Node* head,int index){
        if(head==nullptr){
            return head;
        }
        if(index==1){
            return deletionHead(head);
        }
        Node* temp=head;
        Node *prev=nullptr;
        for(int i=0;i<index && temp!=nullptr;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
        return head;
     }

//deletion node by value
    Node* deletionByValue(Node* head,int value){
        if(head==nullptr){
            return nullptr;
        }
        if(head->data==value){
            return deletionHead(head);
        }

        Node* temp=head;
        Node* prev=nullptr;
        while(temp!=nullptr){
            if(temp->data==value){
            prev->next=temp->next;
            delete temp;
            break;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }

//deleting  last node
     Node* deletionLast(Node* head){
        if(head==nullptr  || head->next==nullptr){
            return nullptr;
        }
        Node* temp=head;
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=nullptr;
        return head;
     }


        
       
int main(){
    vector<int>arr={1,2,3,4,5,6};
    Node* head= arrtoLL(arr);
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
       
    }
    cout<<"NULL"<<endl;
   

//deleting head node
cout<<"After deleting head node: "<<endl;
   head=deletionHead(head);
   temp=head;
   while(temp!=nullptr)
   {
    cout<<temp->data<<"->";
    temp=temp->next;
   }
   cout<<"NULL"<<endl;

   int index;
   cout<<"Enter the index of node you want to delete: ";
   cin>>index;
   

//deleting node at given index
   cout<<"After deleting  node at given index: "<<endl;
   head=deletionAtIndex(head,index);
   temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
       
    }
    cout<<"NULL"<<endl;

    //deleting node of given value
    int value;
   cout<<"Enter the value of data in node you want to delete: ";
   cin>>value;
   cout<<"After deleting  node of particular data value index: "<<endl;
   head=deletionByValue(head,value);
   temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
       
    }
    cout<<"NULL"<<endl;
   

//deleting last index
   cout<<"After deleting  last index: "<<endl;
   head=deletionLast(head);
   temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
       
    }
    cout<<"NULL"<<endl;
   
    return 0;
}