#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(vector<int>& arr) {
    ll len = arr.size();
    sort(arr.begin(), arr.end());
    
    ll median1 = arr[len / 2];
    ll median2 = arr[(len - 1) / 2];
    
    ll cost1 = 0, cost2 = 0;
    for (int i = 0; i < len; i++) {
        cost1 += abs(median1 - arr[i]);
        cost2 += abs(median2 - arr[i]);
    }
    
    cout << min(cost1, cost2);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    solve(arr);
}
