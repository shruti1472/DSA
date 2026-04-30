#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num,int k){
    stack<char>st;
    for(char a:num){
        while(!st.empty() && k>0 && st.top()>a){
            st.pop();
            k--;
        }
        st.push(a);
    }
        while(k>0){
            st.pop();
            k--;
        }

        string res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        int i=0;
        while(!res.empty() && res[i]=='0') i++;
        res=res.substr(i);
        return res.empty() ? "0" : res ;

    }


int main(){
    string num;
    cout<<"enter the string num\n";
    cin>>num;
    int k;
    cout<<"enter the number of digits that are allowed to delete\n";
    cin>>k;
    string ans=removeKdigits(num,k);
    cout<<"the smallest number string after removing k digits is : "<<ans<<endl;

}