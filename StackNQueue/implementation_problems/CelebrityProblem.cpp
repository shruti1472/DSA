#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int celebrityProblem(vector<vector<int>>&M){
    int n=M.size();

    //brute force approach 
    // for(int i=0;i<n;i++){
    //     bool knowSomeone=false;
    //     for(int j=0;j<n;j++){
    //         if(M[i][j]==1){
    //             knowSomeone=true;
    //             break;
    //         }
    //     }
    //     if(!knowSomeone){
    //         bool isCelebrity=true;
    //         for(int j=0;j<n;j++){
    //             if(i!=j && M[j][i]==0){
    //                 isCelebrity=false;
    //                 break;
    //             }
    //         }
    //         if(isCelebrity) return i;
    //     }
    // }
    // return -1;

    int top=0;
    int down=n-1;
    while(top<down){
        if(M[top][down]==1){
            top++;
        }
        else if(M[down][top]==1){
            down--;
        }
        else{
            top++;
            down--;
        }
    }
    if(top>down) return -1;
    for(int i=0;i<n;i++){
        if(top!=i && (M[top][i]!=0 && M[i][top]!=1)){
            return -1;
        }
    }
    return top;
}

int main(){
    int n;
    cout<<"enter the number of people\n";
    cin>>n;
    vector<vector<int>>M(n,vector<int>(n));
    cout<<"enter the values of matrix\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>M[i][j];
        }
    }

    int ans=celebrityProblem(M);
    cout<<"person "<<ans<<" is celebrity\n"; 
}