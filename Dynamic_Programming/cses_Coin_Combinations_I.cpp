#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007


// recursive function O(cost*n), space O(cost)
int h1(vector<int>&coins, int cost, vector<int>&dp){
    if(cost<=0) return cost == 0;
    if(dp[cost]!=-1) return dp[cost];
    int count = 0;
    for(int i=0;i<coins.size();i++) count += h1(coins, cost - coins[i], dp), count%=mod;
    return dp[cost] = count;
}

void solve(vector<int>&coins, int cost){
    vector<int> dp (cost+1, -1);
    cout<<h1(coins, cost, dp);
}

int main(){
    int n, cost;
    cin>>n>>cost;
    vector<int>arr (n);
    for(int i=0;i<n;i++) cin>>arr[i];
    solve(arr, cost);
}
