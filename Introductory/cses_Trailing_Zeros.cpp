#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n;
    cin>>n;
    int fives = 0;
    ll f = 5;
    while(f<=n){
        fives += n/f;
        f *= 5;
    }
    cout<<fives;
}
