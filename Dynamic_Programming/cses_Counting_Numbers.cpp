#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007


// XXXXXX --> these are the places my highest number can have
ll h(string& num, int i, int last, int set, vector<vector<vector<ll>>>& dp) {
    if (i == num.size()) return 1;
    if (dp[i][last][set] != -1) return dp[i][last][set];
    // 1 mean it was tight
    // 0 mean string isn't tight, and has started to construct
    // 2 mean string isn't tight, but has not stated to construct, so no last condition 

    ll count = 0;
    if(set==1){
        int limit = num[i] - '0';
        for(int d = 0; d<limit; d++) {
            if (d!=last) count+=h(num, i + 1, d, 0, dp); // starting the cons
        }
        if(limit!=last) count+=h(num, i+1, limit, 1, dp); // reached limit
    }else if(set==2){
        count+=h(num, i + 1, 0, 2, dp); // again not starting the cons.
        for (int d = 1; d <= 9; d++) {
            count += h(num, i + 1, d, 0, dp); // starging the cons.
        }
    }else{
        for (int d = 0; d <= 9; d++) {
            if (d != last) count += h(num, i + 1, d, 0, dp);
        }
    }
    return dp[i][last][set] = count;
}

ll s(ll n) {
    if(n<0) return 0;
    string num = to_string(n);
    int len = num.size();
    vector<vector<vector<ll>>> dp;
    dp = vector<vector<vector<ll>>>(len, vector<vector<ll>>(11, vector<ll>(3, -1)));
    
    // writing 0th index here
    // so that handling edge cases gets easier
    ll count = 0;
    int limit = num[0] - '0';
    count+=h(num, 1, 0, 2,  dp); // not starting the cons.
    for(int d = 1; d<limit; d++) {
        count+=h(num, 1, d, 0,  dp); // starting the cons
    }
    if(limit!=0) count+=h(num, 1, limit, 1, dp); // reached limit

    return count;
}

void solve(ll a, ll b){
    cout<<s(b) - s(a-1);
}

int main(){
    ll a, b;
    cin>>a>>b;
    solve(a, b);
}
