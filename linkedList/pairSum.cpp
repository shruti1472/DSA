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

vector<pair<int,int>> pairsum(Node* head,int k){
    vector<pair<int,int>>p;

    //brute force approach using two loops worst case time complexity is O(n*n)
    // Node* temp1=head;
    // while(temp1!=nullptr){
    //     Node* temp2=temp1->next;
    //     while(temp2!=nullptr && temp1->data+temp2->data <= k){
    //         if(temp1->data+temp2->data==k){
    //             p.push_back({temp1->data,temp2->data});
    //         }
    //         temp2=temp2->next;
    //     }
    //     temp1=temp1->next;
    // }

    Node*temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* left=head;
    Node* right=temp;
    while(left!=right && right->next != left){
        if(left->data+right->data==k){
            p.push_back({left->data,right->data});
            left=left->next;
            right=right->prev;
        }
        else if(left->data+right->data>k){
            right=right->prev;
        }
        else{
            left=left->next;
        }        
    }
    return p;
}

int main(){
    vector<int>arr={1,2,3,4,9};
    Node* head=arrToLL(arr);
    cout<<"linked list is : ";
    printLL(head);
    vector<pair<int,int>>ans=pairsum(head,5);
    for(auto p:ans){
        cout<<p.first<<","<<p.second<<endl;
    }
}

