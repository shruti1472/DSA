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

Node* reverseLL(Node* head){
    Node* prev=nullptr;
    Node* curr=head;
    while(curr!=nullptr){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

Node* rotationByK(Node* head,int k){
    if(head==nullptr || head->next==nullptr || k==0) return head;
    Node* temp=head;
    int n=0;
    while(temp!=nullptr){
        temp=temp->next;
        n++;
    }
    temp=head;
    k=k%n;
    if(k==0) return head;
    k=n-k-1;
    Node* kthNode=head;
    while(kthNode!=nullptr && k>0){
        kthNode=kthNode->next;
        k--;
    }
    Node* nextNode=kthNode->next;
    kthNode->next=nullptr;
    Node* head1=reverseLL(head);
    Node* head2=reverseLL(nextNode);
    head->next=head2;
    return reverseLL(head1);

}

int main(){
    vector<int>arr={1,2,3,4,5};
    Node* head=arrToLL(arr);
    int k;
    cout<<"enter the value of k: ";
    cin>>k;
    cout<<"linked list before rotation: ";
    printLL(head);
    Node* newHead=rotationByK(head,k);
    cout<<"linked list after right rotation by k: "<<endl;
    printLL(newHead);

}