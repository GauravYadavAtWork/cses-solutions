#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

// 1 1D array (fuck you optimization)
void solve(vector<int>& coins, int cost) {
    int n = coins.size();
    vector<int> dp(cost + 1, 0);
    dp[cost] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = cost; j >= 0; j--) {
            int count = 0;
            if (j + coins[i] <= cost) count += dp[j + coins[i]];
            count += dp[j];
            dp[j] = count % mod;
        }
    }
    cout << dp[0];
}

// optimising the space
void solve3(vector<int>& coins, int cost) {
    int n = coins.size();
    vector<int> next(cost + 1, 0), curr(cost + 1, 0);
    next[cost] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = cost; j >= 0; j--) {
            int count = 0;
            if (j + coins[i] <= cost) count += curr[j + coins[i]] % mod;
            count += next[j] % mod;
            curr[j] = count % mod;
        }
        next = curr;
    }
    cout << next[0];
}

// transforming recursive to iterative
void solve2(vector<int>&coins, int cost){
    int n = coins.size();
    vector<vector<int>> dp (n+1, vector<int>(cost+1, 0));
    for(int i=0;i<=n;i++) dp[i][cost] = 1; // base case

    for(int i=n-1;i>=0;i--){
        for(int j=cost;j>=0;j--){
            int count = 0;
            if(j+coins[i] <= cost) count += (dp[i][j + coins[i]])%mod;
            count += (dp[i+1][j])%mod;
            dp[i][j] = count;
        }
    }
    cout<<dp[0][0];
}

// recursive function O(cost*n)
int h(vector<int>&coins, int i, int cost, int t_cost, vector<vector<int>>&dp){
    if(cost>=t_cost) return cost == t_cost;
    if(i==coins.size()) return 0; // coins over
    if(dp[i][cost]!=-1) return dp[i][cost];
    int count = h(coins, i, cost + coins[i], t_cost, dp); count%=mod;
    count += h(coins, i+1, cost, t_cost, dp); count%=mod;
    return dp[i][cost] = count;
}

void solve1(vector<int>&coins, int cost){
    vector<vector<int>> dp (coins.size(), vector<int>(cost+1, -1));
    cout<<h(coins, 0, 0, cost, dp);
}

int main(){
    int n, cost;
    cin>>n>>cost;
    vector<int>arr (n);
    for(int i=0;i<n;i++) cin>>arr[i];
    solve(arr, cost);
}
