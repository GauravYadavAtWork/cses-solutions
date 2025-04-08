#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

void solve(vector<int>&arr){
    if(arr.size()==1){
        cout<<2*arr[0];
        return;
    }
    sort(arr.begin(), arr.end());
    int right = arr.size()-1, left = 0;
    ll rsum = 0, lsum = 0;
    while(left < right){
        if(rsum<=lsum){
            rsum += arr[right];
            right--;
        }else{
            lsum += arr[left];
            left++;
        }
    }

    // rsum will always be bigger than lsum
    // one element will be remained unadded to rsum and lsum i.e. arr[left]
    cout << (lsum + rsum + arr[left] + max(0LL, abs(lsum - rsum) - arr[left])) << endl;;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr (n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr);
}   