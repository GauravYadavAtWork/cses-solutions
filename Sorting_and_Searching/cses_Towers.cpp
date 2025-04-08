#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

void solve(vector<int>&arr){
    multiset<int> st;
    for(int i=0;i<arr.size();i++){
        auto it = st.upper_bound(arr[i]);
        if(it != st.end()) st.erase(it);
        st.insert(arr[i]);
    }
    cout<<st.size()<<endl;
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