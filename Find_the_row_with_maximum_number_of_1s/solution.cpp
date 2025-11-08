#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// brute force approach

    
  int rowWithMax1s(vector<vector<int>>& mat) {
        int maxcount=-1;
        int index=-1;
        int count=0;
        for(int i =0;i<mat.size();i++){
            int count=-1;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                  count++;
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