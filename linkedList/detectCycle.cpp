#include<iostream>
#include<vector>
#include<unordered_map>
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
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }
    temp->next=head;
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

bool detectcycle(Node* head){
    if(head==nullptr || head->next==nullptr){
        return false;
    }
    //using map to store the visited nodes approach time complexity O(n) and space complexity O(n)
    // unordered_map<Node* ,int>mp;
    // Node* temp=head;
    // while(temp!=nullptr){
    //     if(mp.find(temp)!=mp.end()){
    //         return true;
    //     }
    //     else{
    //         mp[temp]=1;
    //         temp=temp->next;
    //     }
    // }
    // return false;

    //another approach of solving this problem is using the two pointer approach time complexity O(n) and space complexity O(1)

    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;

    }
}

int main(){
    vector<int>arr={1,2,3,4,5};
    Node* head=arrtoLL(arr);
    // printLL(head);
    cout<<"is there a cycle in linked list or not: "<<detectcycle(head)<<endl;
}