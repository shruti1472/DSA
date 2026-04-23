#include<iostream>
#include<stack>
using namespace std;

bool isvalid(string s){
    stack<int>st;
    for(int i=0;i<s.size();i++){
           if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
           }
           else{
            if(st.empty()) return false;
            char ch=st.top();
            st.pop();
            if((s[i]==')' && ch!='(') ||
              (s[i]==']' && ch!='[') ||
               (s[i]=='}' && ch!='{')) return false;
           }
    }
    return st.empty();
}

int main(){
    string s;
    cout<<"enter the string of parenthest\n";
    cin>>s;
    if(isvalid(s)){
        cout<<"it is valid parenthesis\n";
    }
    else{
        cout<<"it is not valid parenthesis\n";
    }
}
