// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s 
// such that every character in t (including duplicates) is included in the window. 
// If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string minWindow(string s,string t){
    int minlen=INT16_MAX;
    int sIndex=-1;
       //brute force approach
    //    for(int i=0;i<s.size();i++){
    //         vector<int>hash(256,0);
            
    //         for(char c:t){
    //             hash[c]++;
    //         }
    //         int count=0;
    //         for(int j=i;j<s.size();j++){
    //             if(hash[s[j]]>0){
    //                 count++;
    //             }
    //             hash[s[j]]--;
    //             if(count==t.size()){
    //                 if(j-i+1<minlen){
    //                     minlen=j-i+1;
    //                     sIndex=i;
    //                 }
    //                 break;
    //             }
    //         }
    //    }

    int i=0,j=0;
    vector<int>hash(256,0);
    int count=0;
    for(char c:t){
        hash[c]++;
    }
    while(j<s.size()){
        if(hash[s[j]]>0){
            count++;
        }
        hash[s[j]]--;
        while(count==t.size()){
            if(j-i+1<minlen){
                minlen=j-i+1;
                sIndex=i;
            }
            hash[s[i]]++;
            if(hash[s[i]]>0){
                count--;
            }
            i++;
        }
        j++;
    }
    
       if(sIndex==-1) return "";
       return s.substr(sIndex,minlen);
}

int main(){
    string s,t;
    cout<<"enter main string\n";
    cin>>s;
    cout<<"enter string you want as in substring or t\n";
    cin>>t;
    string ans=minWindow(s,t);
    cout<<"minimum window substring is: "<<ans<<endl;
}
