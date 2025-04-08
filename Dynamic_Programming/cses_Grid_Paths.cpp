#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

// recursive function O(n)
int h(int n, vector<vector<char>>&grid, int i, int j, vector<vector<int>>&dp){ 
    if(i>=n || j>=n || grid[i][j]=='*') return 0;
    if(i==n-1 && j==n-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int count = 0;
    count += h(n, grid, i+1, j, dp); count %= mod;
    count += h(n, grid, i, j+1, dp); count %= mod;
    return dp[i][j] = count;
}

void solve(int n, vector<vector<char>>&grid){
    vector<vector<int>> dp (n,vector<int>(n,-1));
    cout<<h(n, grid, 0, 0, dp);
}

int main(){
    int n;
    cin>>n; 
    vector<vector<char>> arr(n, vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }
    solve(n, arr);
}
