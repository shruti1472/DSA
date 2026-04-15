#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countlessthan(vector<int>nums,int goal){
    if(goal<0) return 0;
    int l=0,r=0;
    int sum=0;
    int count=0;
    while(r<nums.size()){
        sum+=nums[r];
        while(sum>goal){
            sum-=nums[l];
            l++;
        }
        count=count+r-l+1;
        r++;
    }
    return count;
}

int numSubarrayWithSum(vector<int>nums,int goal){
    
    //applying brute force solution
    //int count=0;
    // for(int i=0;i<nums.size();i++){
    //     int sum=0;
    //     for(int j=i;j<nums.size();j++){
    //         if(sum==goal){
    //             count++;
    //         }
    //         if(sum>goal) break;
    //     }

    // }
    // return count;


    //trying the approach prefixsum
    // unordered_map<int,int>mp;
    // mp[0]=1;
    // int sum=0;
    // int count=0;
    // for(int j=0;j<nums.size();j++){
    //     sum+=nums[j];
    //     if(mp.find(nums[sum-goal])!=mp.end()){
    //         count+=mp[sum-goal];
    //     }
    //     mp[sum]++;
    // }
    // return count;

    //trying optimal apprroach without use of map
    return countlessthan(nums,goal)-countlessthan(nums,goal-1);
    
}

int main(){
    vector<int>arr={0,0,0,0,0};
    int sum;
    cout<<"enter the value of sum"<<endl;
    cin>>sum;
    int ans=numSubarrayWithSum(arr,sum);
    cout<<"number of subarray equivalent to sum: "<<ans<<endl;

}