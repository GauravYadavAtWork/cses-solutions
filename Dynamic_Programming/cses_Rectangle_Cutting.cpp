#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int h(int l, int w, vector<vector<int>>& dp){
    if(l<=0 || w<=0) return 250000;
    if(l==w) return 0;
    if(dp[l][w]!=-1) return dp[l][w];
    int result = 250000;
    for(int i=1;i<=l/2;i++){ // dividing the length into two parts, and keeping the width same
        result = min(result, 1 + h(i, w, dp) + h(l-i, w, dp));
    }
    for(int i=1;i<=w/2;i++){ // dividing the width into two parts, and keeping the length same
        result = min(result, 1 + h(l, i, dp) + h(l, w-i, dp));
    }
    return dp[l][w] = result;
}

void solve(int l, int w){
    vector<vector<int>> dp (l+1, vector<int>(w+1, -1));
    cout<<h(l, w, dp);
}

int main(){
    int l, w;
    cin>>l>>w;
    solve(l, w);
}
