#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

class Solution {
public:
    ll findNthDigit(ll n) {
        if(n==1) return 1;
        ll start = 1, end = n;
        ll num = 1;
        while(start<=end){
            ll mid = start + (end - start)/2;
            if(digits_till_n(mid)>=n){
                num = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        ll leftover = digits_till_n(num) - n + 1;
        ll ans = 0;
        while(leftover>0){
            ans = num%10;
            num /= 10;
            leftover--;
        }
        return ans;
    }
private:
    ll digits_till_n(ll n) {
        ll count = 0, digits = 1, start = 1;
        while (start <= n) {
            ll end = min(n, start * 10 - 1);
            count += (end - start + 1) * digits;
            digits++;
            start *= 10;
        }
        return count;
    }
};

int main(){
    int q;
    cin>>q;
    while(q--){
        ll n;
        cin>>n;
        Solution s;
        cout<<s.findNthDigit(n)<<'\n';
    }
}
