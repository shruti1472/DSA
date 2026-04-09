#include<iostream>
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

//print the ll
void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//insert at end of LL
Node* insertLL(Node* head,int val){
    if(head==nullptr) return new Node(val);
  Node* temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=new Node(val);
  return head;
}


//to create intersection point
Node* getNode(Node* head,int x){
    Node* temp=head;
    int count=0;
    while(temp!=nullptr && count<x){
        temp=temp->next;
        count++;
    }
    return temp;
}

//to find intersection point
Node* intersection(Node* headA, Node* headB){
   
   
    //this is the brute force approach with time complexity O(m*n)
    // Node* tempA=headA;  
    // while(tempA!=nullptr){
    //     Node* tempB=headB;
    //     while(tempB!=nullptr){
    //         if(tempA==tempB){
    //             return tempA;
    //         }
    //         tempB=tempB->next;
    //     }
    //     tempA=tempA->next;
    // }

    //another approach is to use hashing with time complexity O(m+n) and space complexity O(m) or O(n)
    // unordered_map<Node* , int>mp;
    // Node* temp=headA;
    // while(temp!=nullptr){
    //     mp[temp]=1;
    //     temp=temp->next;
    // } 
    // temp=headB;
    // while(temp!=nullptr){
    //     if(mp.find(temp)!=mp.end()){
    //         return temp;
    //     }
    //     temp=temp->next;
    // }
    // return nullptr;

    //another approach is to find the length of both linked list and then 
    //move the pointer of longer linked list by the difference of length 
    //and then move both pointers one step at a time until they point to the same node

    // Node* tempA=headA;
    // int countA=0;
    // while(tempA!=nullptr){
    //     countA++;
    //     tempA=tempA->next;
    // }
    // Node* tempB=headB;
    // int countB=0;
    // while(tempB!=nullptr){
    //     countB++;
    //     tempB=tempB->next;
    // }
    // int skip=0;
    // tempA=headA;
    // tempB=headB;
    // if(countA>countB){
    //     skip=countA-countB;
    //     while(skip){
    //         tempA=tempA->next;
    //         skip--;
    //     }
    // }
    // else{
    //     skip=countB-countA;
    //     while(skip){
    //         tempB=tempB->next;
    //         skip--;
    //     }
    // }
    // while(tempA!=nullptr && tempB!=nullptr){
    //     if(tempA==tempB) return tempA;
    //     tempA=tempA->next;
    //     tempB=tempB->next;
    // }

    //another approach
    Node* tempA=headA;
    Node* tempB=headB;
    while(tempA!=tempB){
        tempA=(tempA!=nullptr)?tempA->next:headB;
        tempB=(tempB!=nullptr)?tempB->next:headA;
    }
    return tempA;
}




int main(){
    Node* headA=nullptr;
    Node* headB=nullptr;
    int n,m,x;
    //creating the first LL
    cout<<"enter number of node in first LL"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        headA=insertLL(headA,val);
    }
    cout<<"first linked list :"<<endl;
    printLL(headA);
cout<<endl;
    cout<<"enter the number of node in 2nd LL before intersection"<<endl;
    cin>>m;
    for(int i=0;i<m;i++){
        int val;
        cin>>val;
        headB=insertLL(headB,val);
    }

    cout<<"enter the value of node where intersection is to be made"<<endl;
    cin>>x;
    Node* tempB=headB;
    while(tempB->next!=nullptr){
        tempB=tempB->next;
    }
    tempB->next=getNode(headA,x);
    cout<<"second linked list :"<<endl;
    printLL(headB);
    cout<<endl;

    Node* ans=intersection(headA,headB);
    if(ans!=nullptr){
        cout<<"intersection point is "<<ans->data<<endl;
    }
    else{
        cout<<"no intersection point"<<endl;
    }
}