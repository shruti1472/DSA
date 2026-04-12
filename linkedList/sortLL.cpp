#include<iostream>
#include<bits/stdc++.h>
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


//creation of linked list
Node* createList(int n){
    if(n==0) return nullptr;
    int x;
    cout<<"enter the elements";
    cin>>x;
    Node* head=new Node(x);
    Node* temp=head;
    for(int i=1;i<n;i++){
        cin>>x;
        temp->next=new Node(x);
        temp=temp->next;
        
    }
    return head;
}

//printing linked list
void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//this is brute force approach where we are using insertion sort so the worst case time complexity is O(n*n)
// Node* insertSorted(Node* head,Node* newNode){
//     if(head==nullptr || newNode->data < head->data){
//         newNode->next=head;
//         return newNode;
//     }
//     Node* temp=head;
//     while(temp->next!=nullptr && temp->next->data < newNode->data){
//          temp=temp->next;
//     }
//     newNode->next=temp->next;
//     temp->next=newNode;
//     return head;
// }

//this is brute force approach where we are using insertion sort so the worst case time complexity is O(n*n)
// Node* sortLL(Node* head){
//     Node* sorted=nullptr;
//     Node* curr=head;
//     while(curr){
//         Node* next=curr->next;
//         curr->next=nullptr;
//         sorted=insertSorted(sorted,curr);
//         curr=next;
//     }
//     return sorted;
// }

//now using conversion method LL to array sort then again array to LL and will take overall O(n+nlogn+n)=O(nlogn)
// Node* sortLL(Node* head){
//     vector<int>arr;
//     Node* temp=head;
//     while(temp!=nullptr){
//         arr.push_back(temp->data);
//         temp=temp->next;
//     }
//     sort(arr.begin(),arr.end());
//     temp=head;
//     int i=0;
//     while(temp!=nullptr){
//         temp->data=arr[i];
//         i++;
//         temp=temp->next;
//     }
//     return head;
// }

Node* merge(Node* l1,Node* l2){
    Node* temp1=l1;
    Node* temp2=l2;
    Node* dummy = new Node(-1);
    Node* temp=dummy;
    while(temp1 && temp2){
        if(temp1->data < temp2->data){
            temp->next=temp1;
            temp1=temp1->next;
        }
        else{
            temp->next=temp2;
            temp2=temp2->next;
        }
        temp=temp->next;
    }
    while(temp1){
        temp->next=temp1;
        temp=temp->next;
        temp1=temp1->next;
    }
    while(temp2){
        temp->next=temp2;
        temp=temp->next;
        temp2=temp2->next;
    }
    return dummy->next;
}

Node* sortLL(Node* head){
    //find the halves
    if(head==nullptr || head->next==nullptr) return head;
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* mid = slow->next;
    slow->next = nullptr;
    Node* left=sortLL(head);
    Node* right=sortLL(mid);
    Node* sorted=merge(left,right);
    return sorted;
}

int main(){
   int n;
   cout<<"enter the number of elements/nodes you want in list"<<endl;
   cin>>n;
   Node* head=createList(n);
   cout<<"unsorted list: ";
   printLL(head);
   Node* sortedLL=sortLL(head);
   cout<<"sorted linked list: ";
   printLL(sortedLL);
}