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
    Node* temp2=head;
    int count=2;
    int i=0;
    while(temp!=nullptr && i<count){
        temp2=temp2->next;
        i++;
    }
    temp->next=temp2;
    return head;
}

int lengthOfLoop(Node* head){
    if(head==nullptr || head->next==nullptr) return 0;
    // unordered_map<Node*,int>mp;
    // int count=0;
    // Node* temp=head;
    // while(temp!=nullptr){
    //     if(mp.find(temp)!=mp.end()){
    //         return count-mp[temp];
    //     }
    //     mp[temp]=count;
    //     count++;
    //     temp=temp->next;
    // }

    //two pointer approach
    Node* fast=head;
    Node* slow=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            int length=1;
            slow=slow->next;
            while(slow!=fast){
                length++;
                slow=slow->next;
            }
            return length;
        }
    }
    return 0;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8};
    Node* head=arrToLL(arr);
    cout<<"length of the loop in linked list is: "<<lengthOfLoop(head)<<endl;
}