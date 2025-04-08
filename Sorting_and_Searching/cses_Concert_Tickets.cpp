#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    int n, m;
    cin>>n>>m;
    int a;
    multiset<int> set;
    for(int i=0;i<n;i++){
        cin>>a;
        set.insert(a);
    }
    for(int i=0;i<m;i++){
        cin>>a;
        auto it = set.upper_bound(a);
        if (it == set.begin()) {
            cout << -1 << '\n';
        } else {
            --it;
            cout << *it << '\n';
            set.erase(it);
        }
    }
}
