#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

// recursive function O(n*sum)
int h(int i, int sum, int n, int target, vector<vector<int>>&dp){ 
    if(sum > target) return 0;
    if(i>n) return sum==target;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int count = 0;
    count += h(i+1, sum+i, n, target, dp); count %= mod;  // take i
    count += h(i+1, sum, n, target, dp); count %= mod;    // skip i
    return dp[i][sum] = count;
}

void solve(int n){
    ll sum = (n*(n+1))/2;
    if(sum&1){ // odd, impossible to break
        cout<<0;
    }else{ // even
        sum/=2;
        vector<vector<int>> dp (n+2, vector<int>(sum+1,-1));
        int result = h(1, 0, n, sum, dp); // but this will be exactly twice
        // but we cannot divide result by 2 as we have used mod for each step, so we need to use inverse mod
        ll inv2 = 500000004; // modulo inverse of 2 (fermet little theorem)
        cout << (1LL * result * inv2) % mod << "\n";
    }
}

int main(){
    int n;
    cin>>n; 
    solve(n);
}
