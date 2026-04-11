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

Node* detectCycle(Node* head){
    if(head==nullptr || head->next==nullptr ){
        return nullptr;
    }

    // Node* temp=head;
    // unordered_map<Node*,int >mp;
    // while(temp!=nullptr){
    //     if(mp.find(temp)!=mp.end()) return temp;
    //     else{
    //         mp[temp]=1;
    //         temp=temp->next;
    //     }
        
    // }
    // return nullptr;

    //two pointer apprach
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
           return slow; 
        }
    }
    return nullptr;
}

Node* arrToLL(vector<int>arr){
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

int main(){
    vector<int>arr={1,2,4,5,0};
    Node* head=arrToLL(arr);
    // printLL(head);
    cout<<"is there cycle in linked list or not and at position: "<<endl;
    Node* cycle=detectCycle(head);
    if(cycle != nullptr){
        cout << "Cycle detected at node with value: " << cycle->data << endl;
    } else {
        cout << "No cycle detected" << endl;
    }
}
