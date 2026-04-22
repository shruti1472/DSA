// Minimum Window Subsequence
// iven strings s1 and s2, return the minimum contiguous substring part of s1, so that s2 is a subsequence of the part.

// If there is no such window in s1 that covers all characters in s2, return the empty string "".
//  If there are multiple such minimum-length windows, return the one with the left-most starting index.


// Example 1

// Input: s1 = "abcdebdde", s2 = "bde"

// Output: "bcde"

// Explanation:

// "bcde" is the answer because it occurs before "bdde" which has the same length.

// "deb" is not a smaller window because the elements of s2 in the window must occur in order.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// bool isSubsequence(string sub ,string t){
//   int i=0;
//   int j=0;
//   while(i<sub.size() && j<t.size()){
//     if(sub[i]==t[j]){
//         j++;
//     }
//     i++;
//   }
//   return j==t.size();
// }

string minWindowSubsequence(string s,string t){
    int minlen=INT16_MAX;
    // string ans;
   
    //brute force approach
    // for(int i=0;i<s.size();i++){
    //     for(int j=i;j<s.size();j++){
         
    //     string sub=s.substr(i , j - i + 1);
    //     if(isSubsequence(sub,t)){
    //         if(j-i+1<minlen){
    //             minlen=j-i+1;
    //             ans=sub;
    //         }
    //     }
    //     }
        
    // }
    // return ans;

    //optimized version
    int startIndex=-1;
    int i=0;
    while(i<s.size()){
        if(s[i]==t[0]){
            
            int j=i;
            int k=0;

            while(j<s.size() && k<t.size()){
                if(s[j]==t[k]){
                    k++;
                }
                j++;
            }
            if(k==t.size()){
            int end=j-1;
            k=t.size()-1;
            j=end;
           
            while(j>=i){
                if(s[j]==t[k]){
                    k--;
                }
                if(k<0) break;
                j--;
            }
            int start=j;
            if(end-start+1<minlen){
                minlen=end-start+1;
                startIndex=start;
            }
            i=start;
        }
    }
        i++;
    }
    if(startIndex==-1) return "";
    return s.substr(startIndex,minlen);
}

int main(){
    string s,t;
    cout<<"enter the main string\n";
    cin>>s;
    cout<<"enter the search string\n";
    cin>>t;
    string ans=minWindowSubsequence(s,t);
    cout<<"minimum continuous sunstring of s1 contain all character of s2 in same order is: "<<ans;

}
