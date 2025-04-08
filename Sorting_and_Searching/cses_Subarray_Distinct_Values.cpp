#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

void solve(vector<int>&arr, int k){
    map<int,int> mp;
    int i = 0, j = 0; ll count = 0;
    while(i<arr.size()){
        mp[arr[i]]++;
        while(mp.size()>k){
            mp[arr[j]]--;
            if(mp[arr[j]]==0) mp.erase(arr[j]);
            j++;
        }
        count += (i-j+1); // valid subarrays ending at i
        i++;
    }
    cout<<count;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> arr (n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr, k);
}