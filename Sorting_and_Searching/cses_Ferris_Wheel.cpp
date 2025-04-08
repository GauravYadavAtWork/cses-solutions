#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve(vector<int>&arr, int limit){
    sort(arr.begin(), arr.end());
    int count = 0, i = arr.size() - 1, j = 0;
    while(j<i){
        if(arr[j] + arr[i] > limit){
            i--;
        }else{
            j++;
            i--;
        }
        count++;
    }
    if(j==i) count++;
    cout<<count;
}

int main(){
    int n, limit;
    cin>>n>>limit;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr, limit);
}
