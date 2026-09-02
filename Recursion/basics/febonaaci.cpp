#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int fibonacci(vector<int>dp,int n){
    if(n<=1){
        return n;
    }
   
    // return fibonacci(n-1)+fibonacci(n-2);

    //solve this by memoization that is top down tp;

    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=fibonacci(dp,n-1)+fibonacci(dp,n-2);
}

int main(){
    int n;
    cout<<"enter the fibonacci number you want\n";
    cin>>n;
     vector<int> dp(n + 1, -1);
    cout<<"fibonacci number at "<<n<<" : "<<fibonacci(dp,n)<<endl;
}