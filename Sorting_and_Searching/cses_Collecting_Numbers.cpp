#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void solve(vector<int>& arr) {
    int count = 1;
    for(int i=2;i<arr.size();i++){
        if(arr[i]<arr[i-1]) count++;
    }
    cout<<count;
}
 
int main(){
    int n, a;
    cin>>n;
    vector<int> arr(n + 1);
    for(int i=0;i<n;i++){
        cin>>a;
        arr[a] = i + 1;
    }
    solve(arr);
}
