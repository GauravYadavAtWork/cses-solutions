#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

// recursive function O(n)
int h(int n, vector<int>&dp){ 
    if(n<=0) return n==0;
    if(dp[n]!=-1) return dp[n];
    ll count = 0;
    for(int i=1;i<=6;i++) count += h(n-i, dp), count%=mod;
    return dp[n] = count;
}
void solve1(int n){
    vector<int> dp (n+1, -1);
    cout<<h(n, dp);
}

// iterative,
void solve(int n){
    vector<int> dp (n+1, 0);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        ll count = 0;
        for(int j=1;j<=6;j++) if(i-j >=0) count += dp[i-j], count%=mod;
        dp[i] = count;
    }
    cout<<dp[n];
}

int main(){
    int n;
    cin>>n;
    solve(n);
}
