#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

void solve(vector<int>&arr, int target){
    ll sum = 0, count = 0;
    map<ll, int>mp;
    mp[0] = 1;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        count += mp[sum-target];
        mp[sum]++;
    }
    cout<<count<<'\n';
}

int main(){
    int n, x;
    cin>>n>>x;
    vector<int>arr (n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr, x);
}