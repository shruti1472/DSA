#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> asteroidsCollision(vector<int>asteroids){
        stack<int>st;
        for(int a: asteroids){
            bool destroyed = false;
            while(!st.empty() && st.top()>0 && a<0){
                if(abs(a)==st.top()){
                    destroyed=true;
                    st.pop();
                    break;
                }
                else if(abs(a)>st.top()){
                    st.pop();
                }
                else{
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed){
                st.push(a);
            }
        }
        vector<int>ans(st.size());
        for(int i=st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
}

int main(){
    int n;
    cout<<"enter the number of asteriods\n";
    cin>>n;
    vector<int>asteroids(n);
    cout<<"enter the value and direction of asteroids\n";
    for(int i=0;i<n;i++){
        cin>>asteroids[i];
    }
    vector<int>ans=asteroidsCollision(asteroids);
    cout<<"asteroids remain after collision: \n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;

}