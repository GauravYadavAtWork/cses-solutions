#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

void solve(vector<int>&arr, ll s){
    sort(arr.rbegin(), arr.rend());
    for(int i=0;i<arr.size();i++){
        s -= (1LL*arr[i]*(i+1));
    }
    cout<<s;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr (n);
    ll sum = 0;
    for(int i=0;i<n;i++){
        int a;
        cin>>arr[i]>>a;
        sum += a;
    }
    solve(arr, sum);
}