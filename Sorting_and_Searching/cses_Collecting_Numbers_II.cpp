#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve(vector<int>& arr, vector<int>&count, int p, int q) {
    
}

int main(){
    int n, m,a;
    cin>>n>>m;
    vector<int> arr(n + 1);
    for(int i=0;i<n;i++){
        cin>>a;
        arr[a] = i + 1;
    }
    int count = 1;
    vector<int>c (arr.size());
    c[1] = 1;
    for(int i=2;i<arr.size();i++){
        if(arr[i]<arr[i-1]) count++;
        c[i] = count;
    }
    // if no queries where there, then c[n] would be our answer
    // now what if we swap p and q, i already have the count for each index, if we swap p q, then
    // the swapped number will cause how much effect and be checked if we check 1 less and 1 more index number, for both of these indexes
    for(int i=0;i<m;i++){
        int p, q;
        solve(arr, c, p, q);
    }
}
