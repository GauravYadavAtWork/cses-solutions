#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve(vector<int>&arr, int t){
    map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        if(mp.find(t-arr[i])!=mp.end()){
            cout<<mp[t-arr[i]]+1<<' '<<i+1;
            return;
        }
        mp[arr[i]] = i;
    }
    cout<<"IMPOSSIBLE";
}

int main(){
    int n, t;
    cin>>n>>t;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    solve(arr, t);
}
