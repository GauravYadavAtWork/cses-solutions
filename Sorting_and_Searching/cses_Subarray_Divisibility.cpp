#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

void solve(vector<int>&arr){
    ll sum = 0, count = 0;
    int n = arr.size();
    map<ll, int>mp;
    mp[0] = 1;
    for(int i=0;i<n;i++){
        sum += arr[i];
        count += mp[(sum%n + n)%n];
        mp[(sum%n + n)%n]++;
    }
    cout<<count<<'\n';
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