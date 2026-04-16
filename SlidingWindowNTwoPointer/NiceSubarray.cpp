// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

 

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

//HINT : treat it as binary array where odd number equal to 1 and even number 0 then found 
// the subarray with sum=k and prefer to question numsubarraywithsum.cpp

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lessthanequal(vector<int>nums,int k){
    int l=0,r=0;
    int count=0;
    int sum=0;
    while(r<nums.size()){
        sum+=nums[r]%2;
        while(sum>k){
            sum-=nums[l]%2;
            l++;
        }
        count+=r-l+1;
        r++;
    }
    return count;
}

int niceSubarray(vector<int>nums,int k){

    //optimal solution with O(n) time complexity
    return lessthanequal(nums,k)-lessthanequal(nums,k-1);

}

int main(){
    int n;
    cout<<"enter the number of element in your array"<<endl;
    cin>>n;
    vector<int>nums(n);
    cout<<"enter elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cout<<"enter number of odd number should be on subarray"<<endl;
    cin>>k;
    int ans=niceSubarray(nums,k);
    cout<<"number of nice subarray is : "<<ans<<endl;
}