#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n==1){
        return 1;
    }
    return n*factorial(n-1);
}

int main(){
    int n;
    cout<<"enter the value of n\n";
    cin>>n;
    cout<<factorial(n)<<endl;
}