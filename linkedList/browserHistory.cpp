#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    string data;
    Node* next;
    Node* prev;

    Node(string data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }

    Node(string data1,Node* next1,Node* prev1){
        this->data=data1;
        this->next=next1;
        this->prev=prev1;
    }
};

class browser{
    public:

    Node* current;

   browser(string homepage){
       current=new Node(homepage);
   }

   void visit(string url){
    Node* newNode=new Node(url);
    Node* temp=current->next;
    while(temp){
        Node* del=temp;
        temp=temp->next;
        delete del;
    }
    current->next=newNode;
    newNode->prev=current;
    current=newNode;
   }

   string back(int steps){
    while(steps){
        if(current->prev) {
            current=current->prev;
            steps--;
        }
        else break;
    }
    return current->data;
   }

   string forward(int steps){
    while(steps){
        if(current->next) {
            current=current->next;
            steps--;
        }
        else break;
    }
    return current->data;
   }

};

int main(){
    browser obj("google.com");

    obj.visit("youtube.com");
    obj.visit("facebook.com");
    obj.visit("twitter.com");

    cout << obj.back(1) << endl;     // facebook
    cout << obj.back(1) << endl;     // youtube
    cout << obj.forward(1) << endl;  // facebook

    obj.visit("linkedin.com");

    cout << obj.forward(2) << endl;  // linkedin
    cout << obj.back(2) << endl;     // youtube
}
