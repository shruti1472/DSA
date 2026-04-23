#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string postTopre(string s){
    stack<string>st;
    for(int i=0;i<s.size();i++){
        char ch=s[i];

        if(isalpha(ch)){
            st.push(string(1,ch));
        }
        else{
            string op2=st.top();st.pop();
            string op1=st.top();st.pop();
            string temp=string(1,ch)+op1+op2;
            st.push(temp);
        }
    }
    return st.top();
}

int main(){
    string s;
    cout<<"enter the string to change from postfix to prefix \n";
    cin>>s;
    cout<<"prefix conversion of s is : "<<postTopre(s)<<endl;
    return 0; 
}