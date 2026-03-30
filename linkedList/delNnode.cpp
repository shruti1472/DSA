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

//delete nth node from end of linked list
Node* delNode(Node* head, int n){
    Node* temp=head;
    int cnt=0;
    if(head==nullptr){
        return head;
    }
    if(head->next==nullptr && n==1){
        delete head;
        return nullptr;
    }

    //brute force approach take two passess
    // while(temp!=nullptr){
    //     cnt++;
    //     temp=temp->next;
    // }
    // if(n==cnt){
    //     Node* newHead=head->next;
    //     delete head;
    //     return newHead;
    // }

    // int index=cnt-n;
    // temp=head;
    // for(int i=1;i<index;i++){
    //     temp=temp->next;
    // }

    //optimal approach using two pointer technique

    Node* dummy=new Node(0,head);
    Node* fast= dummy;
    Node* slow=dummy;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }

    while(fast->next!=nullptr){
        fast=fast->next;
        slow=slow->next;
    }

    Node* delNode=slow->next;
    slow->next=delNode->next;
    delete delNode;
    return dummy->next;
}

void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    Node* head=arrToLL(arr); 
    printLL(head);
    cout<<"enter the value of n:";
    int n;
    cin>>n;
    cout<<"linked list after deleting nth node from end of linked list is:"<<endl;
    Node* head1=delNode(head,n);
    printLL(head1);
    
}
