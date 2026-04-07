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


void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

// Node* reverseLL(Node* head){
//     if(head==nullptr || head->next==nullptr){
//         return head;
//     }
//     Node* newHead=reverseLL(head->next);
//     head->next->next=head;
//     head->next=nullptr;
//     return newHead;
// }


int helper(Node* temp){
    if(temp==nullptr){
        return 1;
    }
    int carry=helper(temp->next);
    temp->data+=carry;
    if(temp->data<10){
        return 0;
    }
    temp->data=0;
    return 1;
    

}
Node* addOne(Node* head){
    int carry=helper(head);
    if(carry!=0){
        Node* newNode= new Node(carry);
        newNode->next=head;
        head=newNode;
    }
    return head;
    // head=reverseLL(head);
    // Node* temp=head;
    // int carry=1;
    // while(temp!=nullptr && carry){
    //     int sum=temp->data+carry;
    //     temp->data=sum%10;
    //     carry=sum/10;

    //     if(carry==0){
    //         break;
    //     }
    //     if(temp->next==nullptr && carry){
    //         temp->next=new Node(carry);
    //         carry=0;
    //     }
    //     temp=temp->next;
    // }
    // head=reverseLL(head);
    // return head;

    //optimal approach without reversing the linked list

}
int main(){
    vector<int>arr={1,2,9};
    Node* head=arrToLL(arr);
    printLL(head);
    //add one to the linked list
    cout<<"After adding one to the linked list: "<<endl;
    head=addOne(head);
    printLL(head);
}