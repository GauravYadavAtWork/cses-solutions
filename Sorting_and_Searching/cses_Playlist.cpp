#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>&arr){
    int i = 0, j = 0, res = 0;
    map<int,int>mp;
    while(i<arr.size()){
        while(mp.find(arr[i])!=mp.end()) mp.erase(arr[j]), j++;
        mp[arr[i]]++;
        res = max(res, i - j + 1);
        i++;
    }
    cout<<res;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr (n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr);
}