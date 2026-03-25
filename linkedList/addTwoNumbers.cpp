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

    Node(int data1 , Node* next1 ){
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
}

//add two numbers
Node* addTwoN(Node* l1,Node* l2){
    int sum=0;
    int rem=0;
    Node* dummy=new Node(0);
    Node* temp3=dummy;
    Node* temp1=l1;
    Node* temp2=l2;

    while(temp1!=nullptr || temp2!=nullptr || rem!=0){
        sum=rem;
        if(temp1){
            sum+=temp1->data;
            temp1=temp1->next;
        }
        if(temp2){
            sum+=temp2->data;
            temp2= temp2->next;
        }
        
         temp3->next=new Node(sum%10);
         rem=sum/10;
         temp3=temp3->next;
    }
    return dummy->next;


}

int main(){
    vector<int>arr1={9,9,9,9,9,9,9};
    vector<int>arr2={9,9,9,9};
    Node* head1=arrtoLL(arr1);
    Node* head2=arrtoLL(arr2);

   cout<<"linked list 1: "<<endl;
   printLL(head1);
   cout<<endl;
  
   cout<<"linked list 2: "<<endl;
   printLL(head2);
   cout<<endl;

   cout<<"linked list after adding:"<<endl;
   Node* head3=addTwoN(head1,head2);
   printLL(head3);
   cout<<endl;

}