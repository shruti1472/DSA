
// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int searchSorted(vector<int>& nums,int target){
    int l=0;
    int h=nums.size()-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return -1;
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
cout<<"enter the target element you want to search\n";
cin>>target;
int ans = searchSorted(nums,target);
cout<<"the target ele is at "<<ans<<" index"<<endl;
}