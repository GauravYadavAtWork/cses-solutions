#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

class Solution {
public:
    ll maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        vector<ll> dp (offers.size(), -1);
        return h(offers, 0, dp);
    }
private:
    ll h(vector<vector<int>>& offers, int i, vector<ll>&dp){
        if(i>=offers.size()) return 0LL; // End of houses no.
        if(dp[i] != -1) return dp[i];
        int jump = bs(offers, i+1, offers[i][1]+1);
        ll take = offers[i][2];
        if(jump != -1) take = offers[i][2] + h(offers, jump, dp);
        ll skip = h(offers, i+1, dp);
        return dp[i] = max(take, skip);
    }
private:
    int bs(vector<vector<int>>& offers, int start, int target){
        int end = offers.size()-1, result = -1;
        while(start<=end){
            int mid = end - (end - start)/2;
            if(offers[mid][0] >= target){
                result = mid;
                end = mid - 1;
            }else start = mid + 1;
        }
        return result;
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr (n, vector<int>(3));
    for(int i=0;i<n;i++) cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    Solution s;
    cout<<s.maximizeTheProfit(n, arr);
}
