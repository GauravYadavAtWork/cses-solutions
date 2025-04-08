#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

void solve(vector<int>&arr){
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        if(!st.empty()) cout<<st.top()+1<<' ';
        else cout<<0<<' ';
        st.push(i);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr (n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr);
}