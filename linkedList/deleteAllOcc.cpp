#include<iostream>
#include<vector>
using namespace std;

class Node {
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
    for(int i=0;i<arr.size();i++){
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
    cout<<"null"<<endl;
}

Node* deletionAllOcc(Node* head,int key){
   
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==key){
            if(temp==head){
                head=temp->next;
            }
            Node* nextNode=temp->next;
            Node* prevNode=temp->prev;
            if(nextNode!=nullptr) nextNode->prev=prevNode;
            if(prevNode!=nullptr) prevNode->next=nextNode;
            free(temp);
            temp=nextNode;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}

int main(){
    vector<int>arr={2,1,2,2,4,7,2,9,2};
    Node* head=arrToLL(arr);
    cout<<"linked list before any changes"<<endl;
    printLL(head);
    Node* newHead=deletionAllOcc(head,2);
    cout<<"linked list after deleting all the occurance of 2"<<endl;
    printLL(newHead);
}