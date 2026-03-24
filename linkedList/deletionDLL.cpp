#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

    public:
    Node(int data1,Node* next1,Node* prev1){
        this->data=data1;
        this->next=next1;
        this->prev=prev1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};

Node* arrtoDLL(vector<int>arr){
     Node* head = new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode= new Node(arr[i]);
        temp->next=newNode;
        newNode->prev=temp;
        temp=newNode;
    }
     return head;
}

void printDll(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        cout<<temp->next<<"(next)";
        cout<<temp->prev<<"(prev)";
        cout<<endl;
        temp=temp->next;

    }
    cout<<"NULL"<<endl;
}

Node* deletionAtHead(Node* head){
    if(head==nullptr){
        return head;
    }
    Node * temp=head;
    head=temp->next;
    delete temp;

    if(head!=nullptr){
        head->prev=nullptr;
    }
    return head;
}

Node* deletionAtTail(Node* head){
    if(head==nullptr){
        return head;
    }
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    Node* temp= head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->prev->next=nullptr;
    delete temp;
    return head;
}

Node* deletionAtIndex(Node* head,int index){
    if(head==nullptr){
        return head;
    }
    if(index==0){
        return deletionAtHead(head);
    }
    Node* temp=head;
    int i=0;
    while(temp!=nullptr && i<index){
        temp=temp->next;
        i++;
    }
    if(temp==nullptr){
        return head;
    }

    if(temp->next==nullptr){
        temp->prev->next=nullptr;
        delete temp;
        return head;
    }
    
    temp->prev->next=temp->next;
    if(temp->next!=nullptr){
        temp->next->prev=temp->prev;
        delete temp;
        return head;
    }
}

Node* deletionByValue(Node* head,int value){
    if(head==nullptr){
        return head;
    }
    if(head->data==value){
        return deletionAtHead(head);
    }
    Node* temp=head;
    while(temp!=nullptr && temp->data!=value){
           temp=temp->next;
    }
    if(temp==nullptr){
        return head;
    }
    temp->prev->next=temp->next;
    if(temp->next!=nullptr){
        temp->next->prev=temp->prev;
    }
    delete temp;
    return head;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9,10};
    Node* head= arrtoDLL(arr);
    printDll(head);

    //deleting head Node
    cout<<"After deleting head node: "<<endl;
    head=deletionAtHead(head);
    printDll(head);

    //deleting tail node
    cout<<"After deleting tail node: "<<endl;
    head=deletionAtTail(head);
    printDll(head);

    //deleting node at given index
    cout<<"After deleting node at index 3: "<<endl;
    head = deletionAtIndex(head,3);
    printDll(head);

    //deleting node by value
    cout<<"After deleting node with value 7: "<<endl;
    head=deletionByValue(head,7);
    printDll(head);
   
}