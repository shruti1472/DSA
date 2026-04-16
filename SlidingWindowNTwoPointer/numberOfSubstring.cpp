// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab",
//  "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numberOfSubstring(string s){
    //brute force approach
    // int count=0;
    
    // for(int i=0;i<s.size();i++){
    //     vector<int>a(3,0);
    //     for(int j=i;j<s.size();j++){
    //           a[s[j]-'a']++;
    //           if(a[0]>=1 && a[1]>=1 && a[2]>=1){
    //             count++;
    //           }
    //     }
    // }
    // return count;

    //better approach
//     vector<int>a(3,0);
//     int count=0;
//     int i=0,j=0;
//     while(j<s.size()){
//         a[s[j]-'a']++;
//         while(a[0]>=1 && a[1]>=1 && a[2]>=1){
//             count+=s.size()-j;
//             a[s[i]-'a']--;
//             i++;
//         }
//         j++;
//     }
//  return count;

//optimal approach
    int a=-1,b=-1,c=-1;
    int i=0;
    int count=0;
    while(i<s.size()){
        if(s[i]=='a') a=i;
        else if(s[i]=='b') b=i;
        else if(s[i]=='c')  c=i;

        if(a!=-1 && b!=-1 && c!=-1){
            count+=min(a,min(b,c))+1;
        }
        i++;
    }
    return count;
}

int main(){
    string s="bbacba";
    cout<<s<<endl;
    int ans=numberOfSubstring(s);
    cout<<"number of substring that has atleast a,b,c in it is : "<<ans<<endl;
}