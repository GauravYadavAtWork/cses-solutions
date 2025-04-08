#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve(int a, int b){
    int d = max(a, b) - min(a, b);
    if((min(a,b) - d)>=0 && (min(a,b) - d)%3==0) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        solve(a, b);
    }
}
