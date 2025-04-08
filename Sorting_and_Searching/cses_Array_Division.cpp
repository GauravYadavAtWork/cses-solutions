#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

bool possible(vector<int>&arr, ll maxtime, ll t){ // break array in t segements with maxtime
    ll count = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>maxtime) return false;
        count += arr[i];
        if(count>maxtime){
            count = arr[i];
            t--;
        }
    }
    return t>0;
}

void solve(vector<int>&arr, int t){
    ll start = 0, end = LLONG_MAX, result = 0;
    while(start<=end){
        ll mid = end - (end - start)/2;
        // cout<<"checking is possible for "<<mid<<" "<<possible(arr, mid, t)<<'\n';
        if(possible(arr, mid, t)){
            result = mid;
            end = mid - 1; // this is a valid divison with maxsum mid
        }else{
            start = mid + 1; // increase the maxsum
        }
    }
    cout<<result<<'\n';
}

int main(){
    int n, t;
    cin>>n>>t;
    vector<int>arr (n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr, t);
}