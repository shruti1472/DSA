#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;
    
    Node(int data1){
        data=data1;
        next=nullptr;
        child=nullptr;
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

Node* createChild(int m){
    if(m==0) return nullptr;
    cout<<"enter the value of  child nodes:";
    int x;
    cin>>x;
    Node* head=new Node(x);
    Node* temp=head;
    for(int i=2;i<=m;i++){
        cin>>x;
        temp->child=new Node(x);
        temp=temp->child;
    }
    return head;

}

Node* merge(Node* l1,Node* l2){
    Node* dummy=new Node(-1);
    Node* temp=dummy;
    while(l1!=nullptr && l2!=nullptr){
        if(l1->data<l2->data){
            temp->child=l1;
            l1=l1->child;
            temp=temp->child;
        }
        else{
            temp->child=l2;
            l2=l2->child;
            temp=temp->child;
        }
        temp->next=nullptr;
    }
    if(l1) temp->child=l1;
    if(l2) temp->child=l2;
    return dummy->child;
}

Node* flattenLinkedList(Node* head){

    //brute force approach because extra space
    // vector<int>arr;
    // Node* temp1=head;
    // while(temp1!=nullptr){
    //     Node* temp2=temp1;
    //     while(temp2!=nullptr){
    //         arr.push_back(temp2->data);
    //         temp2=temp2->child;
    //     }
    //     temp1=temp1->next;
    // }
    // sort(arr.begin(),arr.end());
    // Node* newHead=arrToLL(arr);
    // return newHead;

    //optimal approach

    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* mergeHead=flattenLinkedList(head->next);
    head=merge(head,mergeHead);
    return head;
}



Node* createList(){
  int n;
  cout<<"enter the number of actual nodes in the list: ";
  cin>>n;
  cout<<endl;
  int x;
  cout<<"enter the value of head node: ";
  cin>>x;
  Node* head=new Node(x);
  Node* temp=head;
  for(int i=1;i<n;i++){
    cin>>x;
    temp->next=new Node(x);
    temp=temp->next;
  }
  temp=head;
  int inx=1;
  int m;
  while(temp!=nullptr){
    cout<<"enter child node you want for node "<<inx<<endl;
    cin>>m;
    temp->child=createChild(m);
    temp=temp->next;
    inx++;
  }
  return head;
}
void printLL(Node* head){
    Node* temp1=head;
    while(temp1!=nullptr){
        Node* temp2=temp1;
        while(temp2!=nullptr){
            cout<<temp2->data<<" ";
            temp2=temp2->child;
        }
        cout<<endl;
        temp1=temp1->next;
    }
}



int main(){
    Node* head=createList();
    cout<<"linked list without flattening is:"<<endl;
    printLL(head);
    Node* newHead=flattenLinkedList(head);
    cout<<"linked list after flattening:"<<endl;
    printLL(newHead);

}