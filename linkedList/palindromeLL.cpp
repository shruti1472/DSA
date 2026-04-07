#include<iostream>
#include<vector>
#include<stack>
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

//arr(vector) to linked list
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

//print linked list
void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//checking if linked list is palindrome or not
bool isPalindrome(Node* head){
    
    if(head==nullptr || head->next==nullptr){
        return true;
    }
    //brute force approach first reverse the linked list and then compare both time complexity O(2n) and space complexity O(n)
        // Node* temp=head;
        // Node* dummy=new Node(-1);
        // Node* temp2=dummy;
        // while(temp!=nullptr){
        //     temp2->next=new Node(temp->data);
        //     temp2=temp2->next;
        //     temp=temp->next;
        // }

        // Node* newHead=dummy->next;
        // //reverse the linkedlist
        // Node* prev=nullptr;
        // Node* curr=head;
        // while(head!=nullptr){
        //     head=head->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=head;
        // }

        // while(prev!=nullptr && newHead!=nullptr){
        //     if(prev->data!=newHead->data){
        //         return false;
        //     }
        //     prev=prev->next;
        //     newHead=newHead->next;
        // }


        //another approach by copying it into vector and then checking if vector is palindrome or not time complexity O(n) and space complexity O(n)

    // vector<int>arr;
    // Node* temp=head;
    // while(temp!=nullptr){
    //     arr.push_back(temp->data);
    //     temp=temp->next;
    // }
    // int s=0;
    // int e=arr.size()-1;
    // while(s<e){
    //     if(arr[s++]!=arr[e--]){
    //         return false;
    //     }
    // }

    //another approach by using stack time complexity O(n) and space complexity O(n)

//     stack<int>st;
//     Node*temp=head;
//     while(temp!=nullptr){
//         st.push(temp->data);
//         temp=temp->next;
//     }
//     temp=head;
//     while(temp!=nullptr){
//         if(temp->data!=st.top()){
//             return false;
//         }
//         st.pop();
//         temp=temp->next;
//     }


//optimal approach by reversing the second half of the linked list and then comparing both halves time complexity O(n) and space complexity O(1)


    Node* slow=head;
    Node* fast=head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    //reverse the second part
    Node* prev=nullptr;
    slow=slow->next;
    Node* curr=slow;
    while(slow!=nullptr){
        slow=slow->next;
        curr->next=prev;
        prev=curr;
        curr=slow;
    }

    //compare both halves
    while(prev){
        if(head->data!=prev->data)return false;
        head=head->next;
        prev=prev->next;
    }


        return true;
}




int main(){
    vector<int>arr={1,1,2};
    Node* head=arrToLL(arr);
    printLL(head);
    //is linked list palindrome or not
    cout<<"Is linked list palindrome or not: "<<isPalindrome(head)<<endl;
}

