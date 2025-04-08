#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int t;
    cin>>t;
    set<int>s;
    int n;
    for(int i=0;i<t;i++){
        cin>>n;
        s.insert(n);
    }
    cout<<s.size();
}
