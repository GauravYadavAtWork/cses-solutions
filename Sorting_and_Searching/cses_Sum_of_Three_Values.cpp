#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

int bs(vector<pair<int,int>>&arr, int start, int target){
    int end = arr.size() - 1;
    while(start<=end){
        int mid = end - (end - start)/2;
        if(arr[mid].first == target) return arr[mid].second;
        else if(arr[mid].first > target) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}


void solve(vector<int>&arr, int t){
    vector<pair<int,int>>nums (arr.size());
    for(int i=0;i<arr.size();i++) nums[i] = {arr[i], i};
    sort(nums.begin(), nums.end());
    for(int i = 0; i<nums.size();i++){
        // cout<<"nums "<<nums[i].first<<endl;
        for(int j = i+1;j<nums.size();j++){
            int k = bs(nums, j+1, t - nums[i].first - nums[j].first);
            if(k!=-1){
                cout<<nums[i].second+1<<' '<<nums[j].second+1<<' '<<k+1<<'\n';
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<'\n';
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