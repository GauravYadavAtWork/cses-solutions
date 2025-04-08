#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

// best sol
class Solution2 {
public:
    int knapsack(int total_price, vector<int>& values, vector<int>& weights) {
        int n = values.size();
        vector<int> dp(total_price + 1, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = total_price; j >= weights[i]; --j) {
                dp[j] = max(dp[j], values[i] + dp[j - weights[i]]);
            }
        }

        return dp[total_price];
    }
};

// transforming recursive to iterative
class Solution{
public:
    int knapsack(int total_weight, vector<int>&values, vector<int> &weight) {
        int n = values.size();
        vector<vector<int>> dp(total_weight+1, vector<int>(n+1, 0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=total_weight;j++){
                if(j - weight[i] >= 0) dp[j][i] = max(dp[j][i], values[i] + dp[j - weight[i]][i+1]);
                dp[j][i] = max(dp[j][i], dp[j][i+1]);
            }
        }
        return dp[total_weight][0];
    }
};

// recursive
class Solution1 {
public:
    int knapsack(int total_weight, vector<int>&values, vector<int> &weight) {
        vector<vector<int>> dp(total_weight+1, vector<int>(values.size(), -1));
        return h(weight, values, 0, total_weight, dp);
    }
private:
    int h(vector<int>&weight, vector<int>&value, int i, int total_weight, vector<vector<int>> &dp){
        if(total_weight <= 0) return total_weight==0 ? 0 : INT_MIN;
        if(i==weight.size()) return 0;
        if(dp[total_weight][i]!=-1) return dp[total_weight][i];
        return dp[total_weight][i] = max(value[i] + h(weight, value, i+1, total_weight-weight[i], dp), h(weight, value, i+1, total_weight, dp));
    }
};

int main(){
    int n, w;
    cin>>n>>w;
    vector<int> price (n), pages(n);
    for(int i=0;i<n;i++) cin>>price[i];
    for(int i=0;i<n;i++) cin>>pages[i];
    Solution s;
    cout<<s.knapsack(w, pages, price);
}
