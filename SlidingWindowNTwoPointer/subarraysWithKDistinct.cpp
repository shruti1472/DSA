#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//optimal apprroach
// int atmost(vector<int>nums,int k){
//     int l=0,r=0;
//     int count=0;
//     unordered_map<int,int>mp;
//     while(r<nums.size()){
//         mp[nums[r]]++;
//         while(mp.size()>k){
//             mp[nums[l]]--;
//             if(mp[nums[l]]==0) mp.erase(nums[l]);
//             l++;
//         }
//         count+=r-l+1;
//         r++;
//     }
//     return count;
// }

int subarraysWithKDistinct(vector<int>nums, int k){
    // return atmost(nums,k)-atmost(nums,k-1);
    //brute force approach
    int arrcount=0;
    for(int i=0;i<nums.size();i++){
        int count=0;
        unordered_map<int,int>mp;
        for(int j=i;j<nums.size();j++){
            mp[nums[j]]++;
            if(mp[nums[j]]==1) count++;
            if(count==k) arrcount++;
            if(count>k) break;
            
        }
    }
       return arrcount;
}



int main(){
    int n;
    cout<<"enter the size of array\n";
    cin>>n;
    vector<int>nums(n);
    cout<<"enter the elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cout<<"enter the number of distinct number you want in subarray\n";
    cin>>k;
    int ans=subarraysWithKDistinct(nums,k);
    cout<<"number of subarray with k distinct element is: "<<ans<<endl;

}