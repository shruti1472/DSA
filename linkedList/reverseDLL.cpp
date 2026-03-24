#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }

    public:
    Node(int data1,Node* prev1,Node* next1){
        this->data=data1;
        this->prev=prev1;
        this->next=next1;
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

//reversing a doubly linked list  
Node* reverseDll(Node* head){
    //O(2n) time complexity and O(n) space complexity because of stack space and two pass
    // stack<int>st;
    // Node* temp=head;
    // while(temp!=nullptr){
    //     st.push(temp->data);
    //     temp=temp->next;
    // }
    // temp=head;
    // while(temp!=nullptr){
    //     temp->data=st.top();
    //     st.pop();
    //     temp=temp->next;
    // }
    // return head;


    //O(n) time complexity and O(1) space complexity
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    Node* current=head;
    Node* last=nullptr;

    while(current!=nullptr){
        last=current->prev;
        current->prev=current->next;
        current->next=last;
        current=current->prev;
    }
   return last->prev;
}

int main(){
    vector<int>arr={1,2,3,4,5,5,6};
    Node* head=arrtoDll(arr);
    printDll(head);

    //reversing the ddl
    head=reverseDll(head);
    cout<<"After reversing the doubly linked list: "<<endl;
    printDll(head);
}