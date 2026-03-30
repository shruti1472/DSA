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
    Node*head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }
    return head;
}

Node* sort012(Node* head){

    //brute force approach as it take two traversal
//     int cnt1=0,cnt2=0,cnt0=0;
//     Node* temp=head;
//     while(temp!=nullptr){
//         if(temp->data==0) cnt0++;
//         else if(temp->data==1) cnt1++;
//         else cnt2++;
//         temp=temp->next;
//     }

//     temp=head;
//     while(temp!=nullptr){
//         if(cnt0){
//             temp->data=0;
//             cnt0--;
//         }
//         else if(cnt1){
//             temp->data=1;
//             cnt1--;
//         }
//         else{
//             temp->data=2;
//             cnt2--;
//         }
//         temp=temp->next;
//     }
// return head;

//optimize one by making 2 linked list and merge them
Node* temp=head;
Node* head0=new Node(-1);
Node* head1=new Node(-1);
Node* head2= new Node(-1);

Node* zero=head0;
Node* one=head1;
Node* two=head2;

while(temp!=nullptr){
    if(temp->data==0){
        zero->next=temp;
        zero=zero->next;
    }
    else if(temp->data==1){
        one->next=temp;
        one=one->next;
    }
    else{
        two->next=temp;
        two=two->next;       
    }
     temp=temp->next;
    
}
    zero->next=(head1->next!=nullptr)? head1->next:head2->next;
    one->next=head2->next;
    two->next=nullptr;

    Node* newNode=head0->next;

    delete head1;
    delete head2;
    delete head0;

    return(newNode);
}

void printLL (Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

int main(){
    vector<int>arr={1,0,2,2,1,1,0,2,2,1,1,1};
    Node* head=arrtoLL(arr);
    cout<<"linked list before sorting"<<endl;
    printLL(head);

    cout<<"linked list after sorting 0 1 and 2"<<endl;
     Node* head1=sort012(head);
     printLL(head1);
}