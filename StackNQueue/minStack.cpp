#include<iostream>
#include<stack>
#include <algorithm>
using namespace std;

class MinStack{
    private:
    stack<pair<int,int>>st;

    public:
    MinStack(){

    }

    void push(int val){
       
        int mn = val;
        if (!st.empty()) {
            mn = min(val, st.top().second);
        }

        st.push({val, mn});
    }

    void pop(){
        st.pop();
    }

    int top(){
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main(){
    MinStack ms;
    ms.push(10);
    ms.push(-1);
    ms.push(0);
    cout<<ms.getMin()<<endl;
    ms.pop();
    ms.pop();
    // ms.push(-2);
    cout<<ms.getMin();

}
