#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve(vector<int>&arr, int i, ll sum, ll& totalsum, ll& res){
    if(arr.size()==i){
        res = min(res, abs(totalsum - sum - sum));
        return;
    }
    if(sum > (totalsum/2 + 1)) return;
    solve(arr, i+1, sum + arr[i], totalsum, res);
    solve(arr, i+1, sum, totalsum, res);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr (n);
    ll totalsum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        totalsum += arr[i];
    }
    ll res = LLONG_MAX;
    sort(arr.rbegin(), arr.rend());
    solve(arr, 0, 0, totalsum, res);
    cout<<res;
}
