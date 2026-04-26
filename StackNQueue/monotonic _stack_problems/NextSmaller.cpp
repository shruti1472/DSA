// Given an array of integers arr, your task is to find the Next Smaller Element (NSE) for every element in the array.



// The Next Smaller Element for an element x is defined as the first element to the right of x that is smaller than x.



// If there is no smaller element to the right, then the NSE is -1.


// Example 1

// Input: arr = [4, 8, 5, 2, 25]

// Output: [2, 5, 2, -1, -1]

// Explanation:

// - For 4, the next smaller element is 2.

// - For 8, the next smaller element is 5.

// - For 5, the next smaller element is 2.

// - For 2, there is no smaller element to its right → -1.

// - For 25, no smaller element exists → -1.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int>nums){
vector<int>ans(nums.size(),-1);
// for(int i=0;i<nums.size();i++){
//     for(int j=i+1;j<nums.size();j++){
//         if(nums[j]<nums[i]){
//             ans[i]=nums[j];
//             break;
//         }
//     }
// }

//optimal approach
stack<int>st;
for(int i=nums.size()-1;i>=0;i--){
    while(!st.empty() && st.top()>=nums[i] ){
         st.pop();
    }
    if(!st.empty()) {
        ans[i]=st.top();
    }
    st.push(nums[i]);
}
return ans;
}

int main(){
    int n;
    cout<<"enter the size of the array\n";
    cin>>n;
    vector<int>nums(n);
    cout<<"enter the element of the array\n";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>ans=nextSmaller(nums);
    cout<<"next smaller element of all element of array is:\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}