#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1){
       data=data1;
       next=nullptr;
    }
    Node(int data1, Node* next1){
        this->data=data1;
        this->next=next1;
    }
};

Node* arrToLL(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }
    return head;
}

void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
         temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//reversing a linked list
Node* reverseLL(Node* head){
    //iterative approach
    //    if(head==nullptr || head->next==nullptr){
    //     return head;
    //    }
    //    Node* prev=nullptr;
    //    Node* curr=head;
    //    while(head!=nullptr){
    //     head=head->next;
    //     curr->next=prev;
    //     prev=curr;
    //     curr=head;
    //    }
    //    return prev;

    //recursive approach
    if(head==nullptr || head->next==nullptr){
        return head;
    }
     Node* newHead=reverseLL(head->next);
        Node* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newHead;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    Node* head=arrToLL(arr);
    cout<<"linked list before reversing"<<endl;
    printLL(head);
    Node* newHead=reverseLL(head);
    cout<<"linked list after reversing"<<endl;
    printLL(newHead);
}

