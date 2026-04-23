#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string prefixTopostfix(string s){
  stack<string>st;
  for(int i=s.size()-1;i>=0;i--){
    char ch=s[i];
    
    if(isalnum(ch)){
        st.push(string(1,ch));
    }
    else{
        string op1=st.top();st.pop();
        string op2=st.top();st.pop();
        string temp=op1+op2+string(1,ch);
        st.push(temp);
    }
  }
  return st.top();
}

int main(){
     string s;
    cout<<"enter the string to change from prefix to postfix\n";
    cin>>s;
    cout<<"postfix conversion of s is : "<<prefixTopostfix(s)<<endl;
    return 0; 
}