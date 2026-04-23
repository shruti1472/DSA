#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string prefixToinfix(string s){
    stack<string>st;
    for(int i=s.size()-1;i>=0;i--){
        char ch=s[i];

        if(isalpha(ch)){
            st.push(string(1,ch));
        }

        else{
            string op1=st.top();st.pop();
            string op2=st.top();st.pop();
            string temp='(' + op1 + ch + op2 + ')' ;
            st.push(temp);
        }
    }
    return st.top();

}

int main(){
   string s;
    cout<<"enter the string to change from prefix to infix\n";
    cin>>s;
    cout<<"infix conversion of s is : "<<prefixToinfix(s)<<endl;
    return 0; 
}