#include<iostream>
#include<bits/stdc++.h>
using namespace std;


    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1=a.size();
       int n2=b.size();
       int n=n1+n2;
       if(n1>n2) return kthElement(b,a,k);
       int low=max(0,k-n2);
       int high=min(k,n1);
       int left=k;
       while(low<=high){
        int mid1=low+(high-low)/2;
        int mid2=left-mid1;
        int l1=INT_MIN;
        int l2=INT_MIN;
        int r1=INT_MAX;
        int r2=INT_MAX;
        if(mid1<n1) r1=a[mid1];
        if(mid2<n2) r2=b[mid2];
        if(mid1-1>=0) l1=a[mid1-1];
        if(mid2-1>=0) l2=b[mid2-1];
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
            
        }
        else if(l1 > r2) high=mid1-1;
        else low=mid1+1;
 
       }
    return 0;
    
    }




int main(){
    int n1,n2,k;  
    cout<<"Enter sizes of two arrays and k: \n";  
    cin>>n1>>n2>>k;
    vector<int> a(n1);
    vector<int> b(n2);
    cout<<"Enter elements of first array: \n";
    for(int i=0;i<n1;i++){
        cin>>a[i];
    }

    cout<<"Enter elements of second array: \n";
    for(int i=0;i<n2;i++){
        cin>>b[i];
    }

    int ans=kthElement(a,b,k);
    cout<<"K-th element is: "<<ans<<endl;
    return 0;
}


