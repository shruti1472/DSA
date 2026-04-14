#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOne(vector<int>arr,int k){
    //brute force approach using 2 loop take O(n*n) time
    // int maxlen=0;
    // for(int i=0;i<arr.size();i++){
    //     int zeros=0;
    //     for(int j=i;j<arr.size();j++){
    //         if(arr[j]==0) zeros++;
    //         if(zeros>k) break;

    //         maxlen=max(maxlen,j-i+1);
    //     }
    // }
    // return maxlen;

    
    int i=0,j=0;
    int zeros=0;
    int maxlen=0;
    //better approach using two pointer and sliding window O(2n)
    // while(j<arr.size()){
    //     if(arr[j]==0) zeros++;
    //     while(zeros>k){
    //         if(arr[i]==0){
    //             zeros--;
    //         }
    //         i++;
    //     }
    //     maxlen=max(maxlen,j-i+1);
    //     j++;
    // }

    //make it optimal by removing the inside while loop

    while(j<arr.size()){
        if(arr[j]==0) zeros++;
        if(zeros>k){
            if(arr[i]==0)
            zeros--;
            i++;      
        }
        if (zeros<=k) maxlen=max(maxlen,j-i+1);
        j++;
    }
    return maxlen;
}


int main(){
  
    int n;
    cout<<"number of elements in the vector"<<endl;
    cin>>n;
      vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter the number of zero flip allowed"<<endl;
    int k;
    cin>>k;

    int max1=maxConsecutiveOne(arr,k);
    cout<<"maximum consecutive one after"<<k<<"flip: "<<endl;
    cout<<max1<<endl;
}