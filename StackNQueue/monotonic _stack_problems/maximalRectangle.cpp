#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int largestRectangle(vector<int> & heights){
    stack<int>st;
    int n=heights.size();
    int maxi=0;
    for(int i=0;i<=n;i++){
        int current=(i==n)?0:heights[i];
        while(!st.empty() && heights[st.top()]>current){
            int h=heights[st.top()];
            st.pop();

            int right=i;
            int left=st.empty()?-1:st.top();
            int width=right-left-1;
            int area=width*h;
            maxi=max(maxi,area);
        }
        st.push(i);
    }
    return maxi;
}

int maximalRectangle(vector<vector<char>> &matrix){
int row=matrix.size();
int col=matrix[0].size();
vector<int>heights(col,0);
int maxi=0;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
       if(matrix[i][j]=='1'){
        heights[j]++;
       }
       else{
        heights[j]=0;
       }
    }
    maxi=max(maxi,largestRectangle(heights));
}
return maxi;
}

int main(){
    int row,cols;
    cout<<"enter the number of rows and columns of matrix simultaneously\n";
    cin>>row>>cols;
    vector<vector<char>>matrix(row, vector<char>(cols));
    cout<<"enter the value: \n";
    for(int i=0;i<row;i++){
        for(int j=0;j<cols;j++){
            cin>>matrix[i][j];
        }
    }
    int ans=maximalRectangle(matrix);
    cout<<" the largest rectangle containing only 1's in matrix is:  "<<ans;
    return 0;
}