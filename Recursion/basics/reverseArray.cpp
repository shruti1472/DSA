#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>&arr,int l,int r){
    if(l>=r){
        return;
    }
    swap(arr[l],arr[r]);
    reverse(arr,l+1,r-1);
}

int main(){
    int n;
    cout<<"enter the number of element in the array\n";
    cin>>n;
    vector<int>arr(n);
    cout<<"enter the element of array\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"array after reverse\n";
    reverse(arr,0,n-1);
    for(int i=0;i<n;i++){
          cout<<arr[i]<<" ";
    }
}