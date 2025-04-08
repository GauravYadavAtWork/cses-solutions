#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    long long count = 0;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            count += arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }
    cout<<count;
}
