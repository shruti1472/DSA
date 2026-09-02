// Given a sorted array arr[] (following 0-based indexing) and a number target, 
// find the lower bound of the target in this given array. 
// The lower bound of a number is defined as the smallest index in the 
// sorted array where the element is greater than or equal to the given number.

// Note: If all the elements in the given array are smaller than the target, the lower bound will be the length of the array. 

// Examples :

// Input:  arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
// Output: 3
// Explanation: 3 is the smallest index in arr[] where element (arr[3] = 10) is greater than or equal to 9.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums,int target){
    int l=0;
    int h=nums.size();
    while(l<h){
        int mid=l+(h-l)/2;
        if(nums[mid]>=target){
            h=mid;
        }
        else{
            l=mid+1;
        }
    }
    return l;
}

int main(){
    int n,target;
    cout<<"enter the number of element in array\n";
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
        {
        cin>>nums[i];
        }
    cout<<"enter the target element you want to find lower bound of :\n";
    cin>>target; 
    int ans=lowerBound(nums,target);
    cout<<"lower bound of "<<target<<"is at index "<<ans<<endl;

}