#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkPalidrone(string s,int i){
    
    int n=s.size();
     if(i>=n/2){
        return true;
     }
     if(s[i]!=s[n-i-1]){
        return false;
     }
     
     return checkPalidrone(s,i+1);
}

int main(){
    string s;
    cout<<"enter the string\n";
    cin>>s;
    cout<<"string is palidrone or not: "<<checkPalidrone(s,0);
}