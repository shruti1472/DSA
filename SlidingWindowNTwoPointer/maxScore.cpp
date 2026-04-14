#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>cards,int k){
    int sum=0;
    int maxsum=0;
    for(int i=0;i<k;i++){
        sum+=cards[i];
    }
    maxsum=sum;
    int r=cards.size()-1;
    for(int i=k-1;i>=0;i--){
        sum=sum-cards[i]+cards[r];
        r--;
        maxsum=max(maxsum,sum);
    }
    return maxsum;
}

int main(){
    vector<int>cards={9,7,7,9,7,7,9};
    cout<<"enter the number of cards you can pick"<<endl;
    int k;
    cin>>k;
    int maxscore=maxScore(cards,k);
    cout<<"maximum score you get picking consecutive card either from left or right end is: "<<endl;
    cout<<maxscore<<endl;

}