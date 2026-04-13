#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:

    int data;
    Node* next;
    Node* prev;

    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }

    Node(int data1,Node* next1,Node* prev1){
      this->data=data1;
      this->next=next1;
      this->prev=prev1;
    }
};

Node* arrToLL(vector<int>arr){
   Node* head=new Node(arr[0]);
   Node* temp=head;
   for(int i=1;i<arr.size();i++){
    Node* newNode=new Node(arr[i]);
    temp->next=newNode;
    newNode->prev=temp;
    temp=newNode;
   }
   return head;
}

void printLL(Node* head){
  Node* temp=head;
  while(temp!=nullptr){
    cout<<temp->data<<"<=>";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
}

Node* removeDuplicate(Node* head){
    if(head==nullptr || head->next==nullptr) return head;

    Node* temp1=head;
    Node* temp2=temp1->next;
    while(temp1!=nullptr && temp1->next!=nullptr){
         Node* temp2=temp1->next;
         if(temp2->data==temp1->data){
            Node* nextNode=temp2->next;
            Node* prevNode=temp2->prev;
            if(nextNode) nextNode->prev=prevNode;
            if(prevNode) prevNode->next=nextNode;
            delete(temp2);
         }
         else{
            temp1=temp1->next;
         }
    }
    return head;
}

int main(){
    vector<int>arr={1,1,2,2,3,3,4};
    Node* head=arrToLL(arr);
    cout<<"linked list before the removal of duplicate element: ";
    printLL(head);
    Node* removedup=removeDuplicate(head);
    cout<<"linked list after the removal of duplicate element: ";
    printLL(removedup);



}