#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int kDistinctChar(string s,int k){
    int maxlen=-1;

    //brute force approach
    // for(int i=0;i<s.size();i++){
    //     unordered_map<char,int>mp;
    //     int count=0;
    //     for(int j=i;j<s.size();j++){
    //         mp[s[j]]++;
    //         if(mp[s[j]]==1) count++;
    //         if(count==k){
    //             if(j-i+1>maxlen){
    //                 maxlen=j-i+1;
    //             }
    //         }
    //         if(count>k) break;
    //     }
    // }

    //optimal approach
    unordered_map<char,int>mp;
    int i=0,j=0;
    while(j<s.size()){
        mp[s[j]]++;
        while(mp.size()>k){
            mp[s[i]]--;
            if(mp[s[i]]==0){
                mp.erase(s[i]);
            }
            i++;
        }    
        maxlen=j-i+1;
        j++;
    }
    return maxlen;
}

int main(){
    string s;
    cout<<"enter the string\n";
    cin>>s;
    int k;
    cout<<"enter the value of k\n";
    cin>>k;
    int ans=kDistinctChar(s,k);
    cout<<"the length of longest substring with atmost k distinct character: "<<ans<<endl;

}