#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;


    public:
    Node(int data1,Node* prev1,Node* next1){
        this->data=data1;
        this->prev=prev1;
        this->next=next1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
    };

Node* arrtoDll(vector<int>arr){
    if(arr.size()==0){
        return nullptr;
    }
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



void printDll(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"<->";
        // cout<<temp->next<<"(next)";
        // cout<<temp->prev<<"(prev)";
        // cout<<endl;
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}

//inserting at head
Node* insertAtHead(Node* head,int data){
    Node* newNode= new Node(data);
    if(head==nullptr){
        return newNode;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    return head;
}

//inserting at tail
Node* insertAtTail(Node* head,int data){
    Node* newNode= new Node(data);
    if(head==nullptr){
        return newNode;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    return head;
}

//inserting at given index
Node* insertAtIndex(Node* head,int index,int data){
    
       if(index==0){
        return insertAtHead(head,data);
       }
       Node* temp=head;
        int i=0;
        while(temp!=nullptr && i<index-1){
            temp=temp->next;
            i++;
        }
        if(temp==nullptr){
            return head;
        }
        Node* newNode= new Node(data);
        if(head==nullptr){
            return newNode;
        }
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next=newNode;
        if(newNode->next!=nullptr){
            newNode->next->prev=newNode;
        }
        return head;
}

//inserting after the value
Node* insertByValue(Node* head,int value,int gvalue){
    
    Node* temp=head;
    while(temp!=nullptr && temp->data!=gvalue){
        temp=temp->next;
    }
    if(temp==nullptr){
        return head;
    }
    Node* newNode = new Node(value);
    if(head==nullptr){
        return newNode;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next=newNode;
    if(newNode->next!=nullptr){
        newNode->next->prev=newNode;
    }
    return head;
}


    int main(){
        vector<int>arr={1,2,3,4,5,6};
        Node* head=arrtoDll(arr);
        printDll(head);

        //inserting at head
        cout<<"After inserting at head: "<<endl;
        head=insertAtHead(head,0);
        printDll(head);

        //inserting at tail
        cout<<"After inserting at tail: "<<endl;
        head=insertAtTail(head,7);
        printDll(head);

        //inserting at given index
        cout<<"After inserting at index 3: "<<endl;
        head=insertAtIndex(head,3,10);
        printDll(head);

        //inserting after the value
        cout<<"After inserting after the value 4: "<<endl;
        head=insertByValue(head,11,4);
        printDll(head);
    }
    