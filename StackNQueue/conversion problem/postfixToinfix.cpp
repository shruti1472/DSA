#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string postfixToinfix(string s){
    stack<string>st;
    for(int i=0;i<s.size();i++){
        char ch=s[i];

        if(isalpha(ch)){
            st.push(string(1,ch));
        }
        else{
            string op2=st.top();st.pop();
            string op1=st.top();st.pop();
            string  temp="(" + op1 + string(1,ch) + op2 + ")";
            st.push(temp);
        }
    }
    return st.top();
}

int main(){
    string s;
    cout<<"enter the string to change from postfix to infix\n";
    cin>>s;
    cout<<"infix conversion of s is : "<<postfixToinfix(s)<<endl;
    return 0; 
}