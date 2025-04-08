#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

// recursive function O(n)
int h(int n, vector<int>&dp){ 
    if(n<=0) return n==0 ? 0 : 1000001;
    if(dp[n]!=-1) return dp[n];
    int count = 1000001;
    int num = n;
    while(num){
        int d = num%10;
        if(d) count = min(count, 1 + h(n-d, dp));
        num/=10;
    }
    return dp[n] = count;
}

void solve(int n){
    vector<int> dp (n+1, -1);
    cout<<h(n, dp);
}

int main(){
    int n;
    cin>>n;
    solve(n);
}
