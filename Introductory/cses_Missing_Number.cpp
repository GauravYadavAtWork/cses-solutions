#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll sum = 0;
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a;
        cin>>a;
        sum += a;
    }
    cout<<(1LL*n*(n+1))/2 - sum;
}


