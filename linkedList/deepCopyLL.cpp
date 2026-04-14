#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data1){
        data=data1;
        next=nullptr;
        random=nullptr;
    }
};

Node* createListWithRandom(vector<pair<int,int>>arr){
   vector<Node*>Nodes;
   for(auto it:arr){
        Nodes.push_back(new Node(it.first));
   }

   for(int i=0;i<Nodes.size()-1;i++){
        Nodes[i]->next=Nodes[i+1];
   }
    
   for(int i=0;i<Nodes.size();i++){
        int random=arr[i].second;
        if(random!=-1){
            Nodes[i]->random=Nodes[random];
        }
   }
   return Nodes[0];  
}

void printLL(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << "Node: " << temp->data;

        if(temp->random != NULL)
            cout << " Random: " << temp->random->data;
        else
            cout << " Random: NULL";

        cout << endl;

        temp = temp->next;
    }
}

Node* copyLinkedList(Node* head){
    if(head == NULL) return NULL;
    // unordered_map<Node*,Node*>mp;
    // Node* temp=head;
    // while(temp!=nullptr){
    //     mp[temp]=new Node(temp->data);
    //     temp=temp->next;
    // }
    // temp=head;
    // while(temp!=nullptr){
    //     mp[temp]->next=mp[temp->next];
    //     mp[temp]->random=mp[temp->random];
    //     temp=temp->next;
    // }
    // return mp[head];

    //without extra space
    Node* temp = head;
    //creating a copy node of each node and attach to main list
    while(temp!=nullptr){
        Node* newNode=new Node(temp->data);
        newNode->next=temp->next;
        temp->next=newNode;
        temp=temp->next->next;
    }

    //linking random pointer
    temp=head;
    while(temp!=nullptr){
        if(temp->random!=nullptr){
            temp->next->random=temp->random->next;
        }
        else{
            temp->next->random=nullptr;
        }
        temp=temp->next->next;
    }

    //connecting the next pointer and separating the list
    Node* dummy=new Node(-1);
    Node* copylist=dummy;
    temp=head;
    while(temp!=nullptr){
        Node* copyNode=temp->next;
        copylist->next=copyNode;
        copylist=copylist->next;

        temp->next=copyNode->next;
        temp=temp->next;
    }
    return dummy->next;
}

int main(){
    vector<pair<int,int>>arr ={
    {7, -1},
    {13, 0},
    {11, 4},
    {10, 2},
    {1, 0}
};

Node*  head=createListWithRandom(arr);
printLL(head);
cout<<"copied linked list"<<endl;
Node* copyHead=copyLinkedList(head);
printLL(copyHead);
}