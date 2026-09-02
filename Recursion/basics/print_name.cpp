#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void name(int n){
    if(n==0) return;
    cout<<"shruti\n";
    name(n-1);

}

int main(){
    int n;
    cout<<"enter the numnber of times you want to print the name:\n";
    cin>>n;
  name(n);
}