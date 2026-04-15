#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxBasket(vector<int>fruits){
    int maxlen=0;

    

    //brute force solution using two loops with complexity of O(n*n)
    // for(int i=0;i<fruits.size();i++){
    //     unordered_map<int,int>mp;
    //     int distinct=0;
    //     for(int j=i;j<fruits.size();j++){
    //         if(mp.find(fruits[j])==mp.end()){
    //             distinct++;
    //         }
    //         mp[fruits[j]]++;
    //         if(distinct>2) break;
    //        maxlen=max(maxlen,j-i+1);
    //     }
    // }

    //better solution using two pointer and sliding window with O(2N) complexity
    int i=0;
     unordered_map<int,int>mp;
     for(int j=0;j<fruits.size();j++){
        mp[fruits[j]]++;
        while(mp.size()>2){
            mp[fruits[i]]--;
            if(mp[fruits[i]]==0){
                mp.erase(fruits[i]);
            }
            i++;
        }
        maxlen=max(maxlen,j-i+1);
     }


    //this is optimal solution with O(N) complexity and O(3) space 
    // for(int j=0;j<fruits.size();j++){
    //     mp[fruits[j]]++;
    //     if(mp.size()>2){
    //         mp[fruits[i]]--;
    //         if(mp[fruits[i]]==0) mp.erase(fruits[i]);
    //         i++;
    //     }
    //     if(mp.size()<=2) maxlen=max(maxlen,j-i+1);
    // }
    return maxlen;

}

int main(){
    vector<int>fruits={3,3,3,1,2,1,1,2,3,3,4};
    cout<<"maximum fruits total in both basket is: "<<endl;
    int ans=maxBasket(fruits);
    cout<<ans<<endl;

}
