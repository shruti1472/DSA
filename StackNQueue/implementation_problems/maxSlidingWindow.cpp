// You are given an array of integers nums, there is a sliding window of size k 
// which is moving from the very left of the array to the very right. 
// You can only see the k numbers in the window. 
// Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

//solution

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>nums,int k){
   
   //this is brute force approach taking O(n*k) and if k is too big then complexity will be in n*n 
    // int n=nums.size();
    // vector<int>ans;
    // for(int i=0;i<=n-k;i++){
    //     int maxi=nums[i];
    //     for(int j=i+1;j<i+k;j++){
    //         maxi=max(maxi,nums[j]);
    //     }
    //     ans.push_back(maxi);
    // }
    // return ans;

    //optimal approach using deque so we can remove out of index element from front and smaller element from back
    
    int n=nums.size();
    deque<int>dq;
    vector<int>ans;
    for(int i=0;i<n;i++){

        //removing out of index element  from front 
        if(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }

        while(!dq.empty() && nums[dq.back()] <= nums[i] ){
            dq.pop_back();
        }

        dq.push_back(i);

        if(i >= k-1){
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"enter the size of the array\n";
    cin>>n;
    vector<int>nums(n);
    cout<<"enter the elements: \n";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cout<<"enter the size of the window:\n";
    cin>>k;
    vector<int>arr=maxSlidingWindow(nums,k);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}