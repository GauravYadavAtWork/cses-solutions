#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve(vector<int>&arr){
    sort(arr.begin(), arr.end());
    set<int> st;
    for(int i=0;i<arr.size();i++){
        vector<int>result;
        for(auto &it : st) result.push_back(arr[i]+it);
        st.insert(arr[i]);
        st.insert(result.begin(), result.end());
    }
    cout<<st.size()<<'\n';
    for(auto &it : st) cout<<it<<' ';
}

int main(){
    int n;
    cin>>n;
    vector<int>arr (n);
    for(int i=0;i<n;i++) cin>>arr[i];
    solve(arr);
}
