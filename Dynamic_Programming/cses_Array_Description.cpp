#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int h(vector<int>&arr, int i, int last, int limit, vector<vector<int>>&dp){
    if(i==arr.size()) return 1;
    if(arr[i] && abs(arr[i]-last)>1) return 0;
    if(dp[i][last]!=-1) return dp[i][last];
    // case 1
    if(arr[i] && abs(arr[i]-last)<=1) 
        return dp[i][last] = h(arr, i+1, arr[i], limit, dp); 
    // case 2
    int result = h(arr, i+1, last, limit, dp);
    if(last-1 >0) result += h(arr, i+1, last-1, limit, dp);
    result%=mod;
    if(last+1 <= limit) result += h(arr, i+1, last+1, limit, dp);
    result%=mod;
    return dp[i][last] = result;
}

void solve(vector<int>&arr, int m){
    vector<vector<int>> dp (arr.size(), vector<int>(m+1, -1));
    if(arr[0]) cout<< h(arr, 1, arr[0], m, dp);
    else {
        int count = 0;
        for(int i=1;i<=m;i++) count += h(arr, 1, i, m, dp), count%=mod;
        cout<< count;
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int>arr (n);
    for(int i=0;i<n;i++) cin>>arr[i];
    solve(arr, m);
}
