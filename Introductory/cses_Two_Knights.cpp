#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll b = i*i;
        cout<<((1LL*b*(b-1))/2 - (4LL*(i-1)*(i-2)))<<'\n';
    }
}
