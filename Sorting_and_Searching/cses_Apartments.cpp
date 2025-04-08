#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve(vector<int>&des, vector<int>&aprt, int k){
    sort(des.begin(), des.end());
    sort(aprt.begin(), aprt.end());
    int count = 0, taken = -1;
    for(int i=0;i<des.size();i++){
        int idx = lower_bound(aprt.begin() + taken + 1, aprt.end(), des[i]-k) - aprt.begin();
        if(idx<aprt.size() && aprt[idx]<=des[i]+k){
            taken = idx;
            count++;
        }
    }
    cout<<count;
}

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> des(n);
    vector<int> apart(m);
    for(int i=0;i<n;i++) cin>>des[i];
    for(int i=0;i<m;i++) cin>>apart[i];
    solve(des, apart, k);
}
