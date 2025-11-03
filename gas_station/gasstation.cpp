#include<iostream>
#include<bits/stdc++.h>
using namespace std;


    double minMaxDist(vector<int> &stations, int K) {
        // Code here
    //     if (stations.size() <= 1) return 0.0;

    //     vector<int>placed(stations.size()-1,0);
    //     for(int gas=1;gas<=K;gas++){
    //         double maxvalue=-1;
    //         int maxindex=-1;
    //         for(int i=0;i<stations.size()-1;i++){
    //             long double diff=(stations[i+1]-stations[i]);
    //             long double sectionlength=diff/(long double)(placed[i]+1);
    //             if(sectionlength>maxvalue){
    //                  maxvalue=sectionlength;
    //                  maxindex=i;
    //             }
    //         }
            
    //         placed[maxindex]++;
    //     }
    //     long double ans=-1;
    //     for(int i=0;i<stations.size()-1;i++){
    //         long double diff=(stations[i+1]-stations[i]);
    //         long double possible=diff / (long double)(placed[i]+1);
    //         ans=max(ans,possible);
    //     }
    //  return ans;

    // now a better apporach using priority_queue where elements with higher value are at top
    if (stations.size() <= 1) return 0.0;
        int n=stations.size();
        vector<int>placed(stations.size()-1,0);
        priority_queue<pair<long double,int>>pq;
        
        for(int i=0;i<n-1;i++){
            pq.push({stations[i+1]-stations[i],i});
        }
        
        for(int gas=1;gas<=K;gas++){
            auto tp=pq.top();
            pq.pop();
            int maxindex=tp.second;
            placed[maxindex]++;
            long double diff=stations[maxindex+1]-stations[maxindex];
            long double newvalue=diff/(long double)(placed[maxindex]+1);
            pq.push({newvalue,maxindex});
        }
        
        
     return pq.top().first;
    }
    



int main(){
    int n;
    cout<<"enter the number of statons\n";
    cin>>n;

    vector<int>stations(n);
    cout<<"enter the location/coordinates of station\n";
    for(int i=0;i<stations.size();i++){
        cin>>stations[i];
    }

    int k;
    cout<<"enter the number of new stations to be placed\n";
    cin>>k;

    double ans=minMaxDist(stations,k);
    cout<<"maximum differnce after putting the new gas stations: "<<ans;

}

