//Return the length of the longest substring containing the same letter you can get after replacement of k character
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s,int k){
    int maxlen=0;
    //first go with brute force solution with O(n*n) complexity
    // for(int i=0;i<s.size();i++){
    //     vector<int>freq(26,0);
    //     int maxfreq=0;
    //     for(int j=i;j<s.size();j++){
    //         freq[s[j]-'A']++;
    //         maxfreq=max(maxfreq,freq[s[j]-'A']);
    //         if(j-i+1-maxfreq<=k)  maxlen=max(maxlen,j - i + 1); 
    //     }
    // }
    // return maxlen;


    //optimal solution using sliding window and two pointer with time complexity O(n)
    int i=0,j=0;
    vector<int>freq(26,0);
    int length=0;
    int maxfreq=0;
    while(j<s.size()){
        freq[s[j]-'A']++;
        maxfreq=max(maxfreq,freq[s[j]-'A']);
        length=j-i+1;
        if(length-maxfreq>k){
            freq[s[i]-'A']--;
            i++;
        }
        else{
            maxlen=max(maxlen,length);
        }
        j++;
    }
    return maxlen;
}

int main(){
    string s="AABABBA";
    cout<<s<<endl;
    int k;
    cout<<"enter the value of replacement allowed"<<endl;
    cin>>k;
    int maxlen=characterReplacement(s,k);
    cout<<"maximum repeating character in a subarray is:"<<maxlen<<endl;
}