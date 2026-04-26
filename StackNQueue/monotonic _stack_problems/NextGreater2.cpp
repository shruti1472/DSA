// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
// return the next greater number for every element in nums.

// The next greater number of a number x is the first greater number to its traversing-order next in the array,
// which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

// Example 1:

// Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater2(vector<int>nums){
    int n=nums.size();
    vector<int>ans(n,-1);
    
    //this is brute force approach
    // for(int i=0;i<nums.size();i++){
    //     for(int j=1;j<nums.size();j++){
    //         int curr=(i+j)%nums.size();
    //         if(nums[curr]>nums[i]){
    //             ans[i]=nums[curr];
    //             break;
    //         }
    //     }
    // }

    //optimal approach using stack
    stack<int>st;
    for(int i=2*n-1;i>=0;i--){
        int curr=nums[i%n];
        while(!st.empty() && st.top()<=curr){
            st.pop();
        }
        if(i<n) {
            if(!st.empty()) ans[i]=st.top();
        }
        st.push(curr);
    }
    
    return ans;
}

int main(){
    int n;
    cout<<"enter the size of your vector or array\n";
    cin>>n;
    vector<int>nums(n);
    cout<<"enter the elemnet of the array\n";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>ans=nextGreater2(nums);
    cout<<"next greator array is: \n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}