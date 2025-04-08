#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long n){
    cout<<n<<" ";

    if(n==1) return;
    else if(n&1) n = n*3 + 1;
    else n = n/2;
    solve(n);
}

int main(){
    // int t;
    // cin>>t;
    // while(t--){
    // }
    long long n;
    cin>>n;
    solve(n);
}


