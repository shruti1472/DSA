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

    Node(int data1,Node* next1){
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

Node* getKNode(Node* temp ,int k){
  k=k-1;
  while(temp!=nullptr && k>0){
    temp=temp->next;
    k--;
  }
  return temp;
}

Node* reverseLL(Node* head){
    Node* prev=nullptr;
    Node* curr=head;
    while(curr){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

// time complexity of this (n/k)*(k + k) + (n/k) = 2n + n/k = O(n)

Node* reverseKGroup(Node* head,int k){
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=nullptr){
        Node* kthNode=getKNode(temp,k);
        if(kthNode==nullptr){
            if(prev) prev->next=temp;
            break;
        }
        Node* nextNode=kthNode->next;
        kthNode->next=nullptr;
        reverseLL(temp);
        if(temp==head){
            head=kthNode;
        }
        else{
            prev->next=kthNode;
        }
        prev=temp;
        temp=nextNode;
    }
    return head;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8};
    Node* head=arrToLL(arr);
    int k;
    cout<<"enter the key: "<<endl;
    cin>>k;
    cout<<"linked list before reversing N node: ";
    printLL(head);
    Node* newList=reverseKGroup(head,k);
    cout<<"list after reversing k group: ";
    printLL(newList);

}