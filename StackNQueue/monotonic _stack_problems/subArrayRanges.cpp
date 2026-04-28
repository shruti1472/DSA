//before doing this question and to solve this optimally you should know 
 //how to next,previous smaller element,ans sum of subarray minimums


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> previousSmallerElement(vector<int>nums){
    int n=nums.size();
    stack<pair<int,int>>st;
    vector<int>ans(n,-1);
    for(int i=0;i<nums.size();i++){
        while(!st.empty() && st.top().first >= nums[i]){
            st.pop();
        }
        if(!st.empty()) ans[i]=st.top().second;
        st.push({nums[i],i});
    }  
    return ans;
}

vector<int> nextSmallerElement(vector<int>nums){
    int n=nums.size();
    stack<pair<int,int>>st;
    vector<int>ans(n,n);
    for(int i=nums.size()-1;i>=0;i--){
        while(!st.empty() && st.top().first > nums[i]){
            st.pop();
        }
        if(!st.empty()) ans[i]=st.top().second;
        st.push({nums[i],i});
    }  
    return ans;
}

int sumSubarrayMins(vector<int>nums){
 vector<int>PSE= previousSmallerElement(nums);
 vector<int>NSE= nextSmallerElement(nums);
 int n=nums.size();
 int total=0;
 for(int i=0;i<n;i++){
    int left=i-PSE[i];
    int right=NSE[i]-i;
    total=total + (right*left*nums[i]);
 }
 return total;
}



vector<int> nextLargerElement(vector<int>nums){
    int n=nums.size();
    stack<pair<int,int>>st;
    vector<int>ans(n,n);
    for(int i=nums.size()-1;i>=0;i--){
        while(!st.empty() && st.top().first <= nums[i]){
            st.pop();
        }
        if(!st.empty()) ans[i]=st.top().second;
        st.push({nums[i],i});
    }  
    return ans;
}

vector<int> previousLargerElement(vector<int>nums){
    int n=nums.size();
    stack<pair<int,int>>st;
    vector<int>ans(n,-1);
    for(int i=0;i<nums.size();i++){
        while(!st.empty() && st.top().first < nums[i]){
            st.pop();
        }
        if(!st.empty()) ans[i]=st.top().second;
        st.push({nums[i],i});
    }  
    return ans;
}

int sumSubarrayMaxs(vector<int>nums){
    vector<int>PLE= previousLargerElement(nums);
 vector<int>NLE= nextLargerElement(nums);
 int n=nums.size();
 int total=0;
 for(int i=0;i<n;i++){
    int left=i-PLE[i];
    int right=NLE[i]-i;
    total=total + (right*left*nums[i]);
 }
 return total;
}

long long subArrayRanges(vector<int>nums){
      int MOD=1e9+7;
//    long long total=0;
//    for(int i=0;i<nums.size();i++){
//     int mini = INT_MAX;
//     int maxi = INT_MIN;
//     for(int j=i;j<nums.size();j++){
//         maxi=max(maxi,nums[j]);
//         mini=min(mini,nums[j]);
//         total+=(maxi-mini);
//     }
//    }
//    return total;
return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
}


int main(){
int n;
cout<<"enter the number of elements in the array\n";
cin>>n;
vector<int>nums(n);
for(int i=0;i<n;i++){
    cin>>nums[i];
}
int sum=subArrayRanges(nums);
cout<<"sum of subarray ranges: \n"<<sum<<endl;
}