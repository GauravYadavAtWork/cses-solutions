#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

// best solution
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> dp(amount+1, 0);
        dp[0] = 1;

        for(auto coin : coins) {
            for(int i = coin; i <= amount; i++) {
                dp[i] += dp[i-coin];
            }
        }

        return dp[amount];
    }
};

// recursive function O(cost*n)
int h(vector<int>&coins, int i, int cost, vector<vector<int>>&dp){
    if(cost<=0) return cost == 0;
    if(i==coins.size()) return 0; // coins over
    if(dp[i][cost]!=-1) return dp[i][cost];
    int count = h(coins, i, cost - coins[i], dp); count%=mod;
    count += h(coins, i+1, cost, dp); count%=mod;
    return dp[i][cost] = count;
}

void solve(vector<int>&coins, int cost){
    vector<vector<int>> dp (coins.size(), vector<int>(cost+1, -1));
    cout<<h(coins, 0, cost, dp);
}

int main(){
    int n, cost;
    cin>>n>>cost;
    vector<int>arr (n);
    for(int i=0;i<n;i++) cin>>arr[i];
    solve(arr, cost);
}
