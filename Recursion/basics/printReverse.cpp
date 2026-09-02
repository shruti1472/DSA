#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printRev(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    printRev(n-1);
}

int main(){
    int n;
    cout<<"enter the value of n\n";
    cin>>n;
    printRev(n);
}