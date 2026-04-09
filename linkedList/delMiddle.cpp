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

void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

Node* deletemid(Node* head){
    if(head == nullptr || head->next == nullptr){
    return nullptr;
}

//count and the delete middle index node approach
    // Node* temp=head;
    // int count=0;
    // while(temp!=nullptr){
    //     count++;
    //     temp=temp->next;
    // }
    // int index=count/2;
    // temp=head;
    // for(int i=1;i<index;i++){
    //     temp=temp->next;
    // }
    // Node* delnode=temp->next;
    // temp->next=delnode->next;
    // delete delnode;

    //slow and fast pointer approach
    Node* fast=head;
    Node* slow=fast;
    Node* temp=head;
    while(fast!=nullptr && fast->next!=nullptr){
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;

    }
    temp->next=slow->next;
    delete slow;
    return head;
}

int main(){
    vector<int>arr={1,2};
    Node* head=arrtoLL(arr);
    cout<<"linked list before deletion:"<<endl;
    printLL(head);
    
    head=deletemid(head);
    cout<<"linked list after deletion of middle node:"<<endl;
    printLL(head);
}