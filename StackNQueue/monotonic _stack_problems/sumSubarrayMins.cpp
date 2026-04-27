// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
// Since the answer may be large, return the answer modulo 109 + 7.

 

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> previousSmallestElemnet(vector<int>arr){
    int n=arr.size();
    vector<int>ans(n,-1);
    stack<pair<int,int>>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top().first>arr[i]){
            st.pop();
        }
        if(!st.empty()) ans[i]=st.top().second;
        st.push({arr[i],i});
    }
    return ans;
}

vector<int> nextSmallestElement(vector<int>arr){
    int n=arr.size();
    vector<int>ans(n,n);
    stack<pair<int,int>>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top().first>=arr[i]){
            st.pop();
        }
        if(!st.empty()) ans[i]=st.top().second;
        st.push({arr[i],i});
    }
    return ans;
}

int sumSubarrayMins(vector<int>arr){
    int n=arr.size();
    
    //first we go for brute force approach where we use two loops leads to time complexity O(n*n)
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum+=arr[i];
//         int mini=arr[i];
//         for(int j=i+1;j<n;j++){
//             mini=min(mini,arr[j]);
//             sum+=mini;
//         }
//     }
//     return sum; 
// }
 

//       optimise version where we use next smaller element and previous smallest element which can be found using monotonic stack.
//       the intitution is figure out each element contributing how many times in the sum and by multiply pse and nse we got that .

       vector<int>PSE=previousSmallestElemnet(arr);
       vector<int>NSE=nextSmallestElement(arr);
       long long total=0;
       int MOD=1e9+7;
       for(int i=0;i<n;i++){
            int left=i-PSE[i];
            int right=NSE[i]-i;
            total=(total + ( 1LL * left * right  % MOD) * arr[i]) % MOD;
       }
       return total;
}

int main(){
    int n;
    cout<<"enter the number of element in array\n";
    cin>>n;
    vector<int>arr(n);
    cout<<"enter the elements of array\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=sumSubarrayMins(arr);
    cout<<"sum of subarray minimums: "<<sum<<endl;
    return 0;
}