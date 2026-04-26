
// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of
//  nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

// Example 1:

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater1(vector<int>& nums1, vector<int>& nums2){

    //brute force approach using two loops
    // vector<int>ans(nums1.size(),-1);
    // for(int i=0;i<nums1.size();i++){
    //     int found=-1;
    //     for(int j=0;j<nums2.size();j++){
    //         if(nums1[i]==nums2[j]){
    //             found=j;
    //             break;
    //         }
    //     }
    //     if(found!=-1){
    //         for(int k=found+1;k<nums2.size();k++){
    //             if(nums2[k]>nums1[i]){
    //                 ans[i]=nums2[k];
    //                 break;
    //             }
    //         }
    //     }
    // }
    // return ans;

    //optimize one solve using monotonic stack in decreasing order
    stack<int>st;
    unordered_map<int,int>mp;
    for(int i=nums2.size()-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums2[i]){
            st.pop();
        }

        if(st.empty()) mp[nums2[i]]=-1;
        else mp[nums2[i]]=st.top();
        st.push(nums2[i]);
    }
    vector<int>ans;
    for(int i=0;i<nums1.size();i++){
        ans.push_back(mp[nums1[i]]);
    }
    return ans;
}

int main(){
    int n,m;
    cout<<"enter the value of n and m\n";
    cin>>n>>m;
    vector<int>nums1(m);
    vector<int>nums2(n);
    cout<<"enter the elemnets of nums2 i.e main array\n ";
    for(int i=0;i<n;i++){
        cin>>nums2[i];
    }
    cout<<"enter the elemnets of nums1 i.e subset array\n ";
    for(int i=0;i<m;i++){
        cin>>nums1[i];
    }
    vector<int>ans=nextGreater1(nums1,nums2);
    cout<<"ans array is:\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}