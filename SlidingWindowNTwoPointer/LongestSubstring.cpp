#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s){
    //first brute force approach using hashmap and double loop with time complexity O(n*n)
    // int maxlen=0;
    // for(int i=0;i<s.size();i++){
    //     int hash[256]={0};
    //     for(int j=i;j<s.size();j++){
    //         if(hash[s[j]]==1) break;
    //         maxlen=max(maxlen,j-i+1);
    //         hash[s[j]]=1;
    //     }
    // }
    // return maxlen;

    //better approach where we are using two pointer  with time O(n+n)
    // int l=0,r=0;
    // int hash[256]={0};
    // int maxlen=0;
    // while(r<s.size()){
    //     if(hash[s[r]]==1){
    //         while(hash[s[r]]==1){
    //             hash[s[l]]=0;
    //             l++;
    //         }
    //     }
    //     hash[s[r]]=1;
    //     maxlen=max(maxlen,r-l+1);
    //     r++;
    // }
    // return maxlen;

    //optimal solution with O(n) time complexity
    int i=0,j=0;
    int maxlen=0;
    int hash[256]={0};
    while(j<s.size()){
       if(hash[s[j]]==0){
        hash[s[j]]++;
        j++;
       }
       else{
        hash[s[i]]--;
        i++;
       }
       maxlen=max(maxlen,j-i);
    }
    return maxlen;

}

int main(){
    string s="";
    int n;
    cout<<"enter the length of the string"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        char a;
        cin>>a;
        s+=a;
    }
int LongestSubstring=longestSubstring(s);
cout<<"length of longest substring without repeating character :"<<endl;
cout<<LongestSubstring;

}