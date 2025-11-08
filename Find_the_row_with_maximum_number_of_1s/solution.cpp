#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// brute force approach

    
  // int rowWithMax1s(vector<vector<int>>& mat) {
  //       int maxcount=-1;
  //       int index=-1;
  //       int count=0;
  //       for(int i =0;i<mat.size();i++){
  //           int count=-1;
  //           for(int j=0;j<mat[i].size();j++){
  //               if(mat[i][j]==1){
  //                 count++;
  //                }
  //           }
  //           if(count>maxcount){
  //             maxcount=count;
  //             index=i;
  //           }
            
             
  //         }
  //         return index;
  // }

      // optimal approach using binary search
  int rowWithMax1s(vector<vector<int>> &arr) {
        int maxcount=0;
        
        int index=-1;
        for(int i=0;i<arr.size();i++){
            int count=0;
            int low=0;
            int high=arr[i].size()-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(arr[i][mid]==1){
                    count=(high-mid+1)+count;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            if(count>maxcount){
                maxcount=count;
                index=i;
            }
        }
        return index;
      }  


  int main(){
      int n,m;  
      cout<<"Enter number of rows and columns: \n";  
      cin>>n>>m;
      vector<vector<int>> mat(n,vector<int>(m));
      cout<<"Enter elements of matrix: \n";
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              cin>>mat[i][j];
          }
      }

      int ans=rowWithMax1s(mat);
      cout<<"Row with maximum 1's is: "<<ans<<endl;
      return 0;
    }