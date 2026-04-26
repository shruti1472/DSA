#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int tappingWater(vector<int>&heights){
    // int total=0;
    // int n=heights.size();
    // if(n == 0) return 0;
    
    // vector<int>prefix(n);
    // prefix[0]=heights[0];
    
    // for(int i=1;i<n;i++){
    //     prefix[i]=max(prefix[i-1],heights[i]);
    // }
    
    // int rightmax=0;
    // for(int i=n-1;i>=0;i--){
    //     rightmax=max(rightmax,heights[i]);
    //    int water=min(prefix[i],rightmax)-heights[i];
    //    if(water >0){
    //     total +=water;
    //    }
    // }
    
    // return total;

    //more optimal solution
    int total=0;
    int lmax=0,rmax=0;
    int l=0,r=heights.size()-1;
    while(l<r){
        if(heights[l]<heights[r]){
            if(lmax>heights[l]){
                total+=lmax-heights[l];
            }
            else{
                lmax=heights[l];
            }
            l++;
        }
        else{
            if(rmax>heights[r]){
                total+=rmax-heights[r];
            }
            else{
                rmax=heights[r];
            }
            r--;
        }
    }

}

int main(){
    // int n;
    // cout<<"enter the number of buildings\n";
    // cin>>n;
    // vector<int>heights(n);
    // cout<<"enter the heights of the building\n";
    // for(int i=0;i<n;i++){
    //     cin>>heights[i];
    // }
    vector<int>heights={4,2,5,3,2,1};
    int ans=tappingWater(heights);
    // cout<<"total taping water is: "<<ans<<endl;
    cout<<"total tapping water is: "<< ans <<"\n";
    return 0;
}