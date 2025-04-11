#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

// game theory
// recursive function O(n*n)
ll h(vector<int>&arr, int i, int j, vector<vector<ll>>&dp){ 
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int turn = (arr.size() - (j - i + 1)) % 2;
    if(!turn){
        return dp[i][j] = 0LL + max(arr[i] + h(arr, i+1, j, dp), arr[j] + h(arr, i, j-1, dp));
    }else{
        return dp[i][j] = 0LL + min(h(arr, i+1, j, dp), h(arr, i, j-1, dp));
    }
}

void solve(vector<int>&arr){
    int n = *max_element(arr.begin(), arr.end());
    // if we find the answer for n, then we can answer for each testcase in the constant time
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // h(arr, 0, n-1, dp);
    // for(int i=0;i<arr.size();i++){

    // }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr (n);
    for(int i=0;i<n;i++) cin>>arr[i];
    solve(arr);
}
