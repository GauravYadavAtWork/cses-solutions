#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

// recursive function O(cost*n)
int h(vector<int>&coins, int i, int cost, vector<vector<int>>&dp){
    if(cost<=0) return cost == 0 ? 0 : 1000001;
    if(i==coins.size()) return 1000001; // coins over
    if(dp[i][cost]!=-1) return dp[i][cost];
    int count = 1000001;
    count = min(count, h(coins, i, cost - coins[i], dp));
    count = min(count, h(coins, i+1, cost, dp));
    return dp[i][cost] = count;
}

// recursive function O(cost*n), space O(cost)
int h1(vector<int>&coins, int cost, vector<int>&dp){
    if(cost<=0) return cost == 0 ? 0 : 1000001;
    if(dp[cost]!=-1) return dp[cost];
    int count = 1000001;
    for(int i=0;i<coins.size();i++) count = min(count, 1 + h1(coins, cost - coins[i], dp));
    return dp[cost] = count;
}

void solve(vector<int>&coins, int cost){
    // vector<vector<int>> dp (coins.size(), vector<int>(cost+1, -1));
    // int r = h(coins, 0, cost, dp);
    vector<int> dp (cost+1, -1);
    int r = h1(coins, cost, dp);
    r>=1000001 ? cout<<-1 : cout<<r;
}

int main(){
    int n, cost;
    cin>>n>>cost;
    vector<int>arr (n);
    for(int i=0;i<n;i++) cin>>arr[i];
    solve(arr, cost);
}
