#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// vector<int> nextSmallerElement(vector<int>heights){
//     int n=heights.size();
//     stack<pair<int,int>>st;
//     vector<int>ans(n,n);
//     for(int i=n-1;i>=0;i--){
//         while(!st.empty() && st.top().first >= heights[i]){
//             st.pop();
//         }
//         if(!st.empty()) ans[i]=st.top().second;
//         st.push({heights[i],i});
//     }
//     return ans;
// }

// vector<int> previousSmallerElement(vector<int>heights){
    // int n=heights.size();
    // stack<pair<int,int>>st;
    // vector<int>ans(n,-1);
    // for(int i=0;i<n;i++){
    //     while(!st.empty() && st.top().first >= heights[i]){
    //         st.pop();
    //     }
    //     if(!st.empty()) ans[i]=st.top().second;
    //     st.push({heights[i],i});
    // }
    // return ans;
// }

int largestRectangleArea(vector<int> &heights){

    //here we find next smaller element and previous smaller element then find the largest rectangle
    // vector<int>PSE=previousSmallerElement(heights);
    // vector<int>NSE=nextSmallerElement(heights);
    // int n=heights.size();
    // int maxi=0;
    // for(int i=0;i<n;i++){
    //   int area=(NSE[i]-PSE[i]-1) * heights[i];
    //   maxi=max(maxi,area);
    // }
    // return maxi;

    //we can use the single monotonic stack
    stack<int>st;
    int n=heights.size();
    int maxi=0;
    for(int i=0;i<=n;i++){
        int current=(i==n)?0:heights[i];
        while(!st.empty() && heights[st.top()]>current){
            int h=heights[st.top()];
            st.pop();

            int right=i;
            int left=st.empty()? -1:st.top();
            int width=right-left-1;
            int area=width*h;
            maxi=max(maxi,area);
        }
        st.push(i);
    }
    return maxi;
}

int main(){
    int n;
    cout<<"enter the number of bars in histogram\n";
    cin>>n;
    vector<int>heights(n);
    cout<<"enter the heights of the bars of the histogram\n";
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }
    int ans=largestRectangleArea(heights);
    cout<<"the area of largest rectangle in histogram is : "<<ans<<endl;;
}