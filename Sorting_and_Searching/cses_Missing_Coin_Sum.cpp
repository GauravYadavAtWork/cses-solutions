#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    ll sum = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] <= sum+1) sum += arr[i];
        else{
            cout<<sum+1;
            return;
        }
    }
    cout<<sum+1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    solve(arr);
}
