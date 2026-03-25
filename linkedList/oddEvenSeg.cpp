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

Node* arrtoLL(vector<int>arr){
    Node* head=new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        Node* newNode= new Node(arr[i]);
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

//odd even segregation of linked list
Node* oddEvenSeg(Node* head){
    //O(n) time complexity and O(1) space complexity
    if(head==nullptr || head->next==nullptr){
        return head;
    }

   //brute for approach with time complexity O(n) and space complexity O(n) because of stack space and two pass
   vector<int>arr;
   Node* temp=head;
   while(temp!=nullptr && temp->next!=nullptr){
    arr.push_back(temp->data);
    temp=temp->next->next;
   }
   if(temp) arr.push_back(temp->data);

   temp=head->next;
   while(temp!=nullptr && temp->next!=nullptr){
    arr.push_back(temp->data);
    temp=temp->next->next;
   }
   if(temp) arr.push_back(temp->data);

   temp=head;
   int i=0;
   while(temp!=nullptr){
    temp->data=arr[i++];
    temp=temp->next;
   }

   

    //O(n) time complexity and O(1) space complexity
    // Node* odd=head;
    // Node* even=head->next;
    // Node* evenhead=even;
    // while(even!=nullptr && even->next!=nullptr){
    //     odd->next=even->next;
    //     odd=odd->next;
    //     even->next=odd->next;
    //     even=even->next;
    // }

    // odd->next=evenhead;
    return head;
}


int main(){
    vector<int>arr={2,1,3,5,6,4,7};
    Node* head=arrtoLL(arr);
    cout<<"original linked list is: "<<endl;
    printLL(head);

    cout<<"after odd even segregation: "<<endl;
    head=oddEvenSeg(head);
    printLL(head);

}