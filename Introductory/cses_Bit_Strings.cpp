#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n;
    cin>>n;
    int m = 1;
    while(n--){
        m *= 2;
        m %= mod;
    }
    cout<<m;
}
