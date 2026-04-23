#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int precedence(char ch){
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    else return -1;
}

bool isMatching(char open,char close){
    if(open=='(' && close==')') return true;
    else if(open=='[' && close==']') return true;
    else if(open=='{' && close=='}') return true;
    return false;
}


string infixToPostfix(string s){
    string ans="";
    stack<char>st;
    for(char ch:s){

       if(isalpha(ch)){
        ans+=ch;
       }

       else if(ch=='(' || ch=='[' || ch=='{'){
           st.push(ch);
       }

       else if(ch==')' || ch==']' || ch=='}'){
            while(!st.empty() && !isMatching(st.top(),ch)){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
       }

       else{
        while(!st.empty() && precedence(st.top())>=precedence(ch) 
           &&  st.top()!='(' && st.top()!='[' && st.top()!='{'){
            if(ch=='^' && st.top()=='^') break;
            ans+=st.top();
            st.pop();
           }
           st.push(ch);
       }
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

int main(){
    string s;
    cout<<"enter the string to change from infix to postfix\n";
    cin>>s;
    cout<<"postfix conversion of s is : "<<infixToPostfix(s)<<endl;
    return 0;
}