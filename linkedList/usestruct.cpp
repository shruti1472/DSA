// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{    //use class for objects oriented programming
public:
    int data;
    Node* next;
    
public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
};

int main() {
    // Write C++ code here
vector<int>arr={1,2,3,4};
Node* z=new Node(arr[0],nullptr);               //creating pointer
cout<<z<<endl; //printing address of the pointer             
cout<<z->data<<endl;      //printing data part of the pointer
Node y= Node(arr[0],nullptr);   //creating a object
cout<<y.data<<endl;    //will print 10
cout<<y.next<<endl;

}