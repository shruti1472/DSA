#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printnum(int n){
if(n==0){
    return;
}
printnum(n-1);
cout<<n<<" ";
}

int main(){
    int n;
    cout<<"enter the numeber till what you want to print the numbers\n";
    cin>>n;
    printnum(n);
}