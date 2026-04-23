//to convert infix to prefix first we reverse the infix string then swap the opening closeing braket then convert that into postfix and then reverse it

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int preference(char ch){
        if(ch=='^') return 3;
        else if(ch=='*' || ch=='/') return 2;
        else if(ch=='+' || ch=='-') return 1;
        return -1;
} 

bool isMatching(char open ,char close){
        if(open=='(' && close==')') return true;
        else if(open=='{' && close=='}') return true;
        else if(open=='[' && close==']') return true;
        return false;
}

string infixTopostfix(string s){
    stack<char>st;
    string ans="";
    for(char ch:s){
            
        if(isalpha(ch)){
            ans+=ch;
        }

        else if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
            
        else if(ch==')' || ch=='}' || ch==']'){
            while(!st.empty() && !isMatching(st.top(),ch)){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }

        else{
            while(!st.empty() && st.top()!='(' && st.top()!='{' && st.top()!='[' 
            && preference(st.top())>preference(ch)
             ){
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

string infixToprefix(string s){
    reverse(s.begin(),s.end());

    for(char &ch:s){
        if(ch=='(') ch=')';
        else if(ch==')') ch='(';
        else if(ch=='[') ch=']';
        else if(ch==']') ch='[';
        else if(ch=='{') ch='}';
        else if(ch=='}') ch='{';
    }

    string postfix=infixTopostfix(s);
    reverse(postfix.begin(),postfix.end());
    return postfix;
}



int main(){
    string s;
    cout<<"enter the string to change from infix to prefix\n";
    cin>>s;
    cout<<"prefix conversion of s is : "<<infixToprefix(s)<<endl;
    return 0; 
}