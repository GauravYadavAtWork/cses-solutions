#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;

int h(int n, int i, int jump, int arr[], vector<int>&memo){
    if(i>=n) return 0;
    if(memo[i]!=-1) return memo[i];
    int* pos = lower_bound(arr + i + 1, arr + n, arr[i] + jump);
    int validJumpPos = pos - arr;
    return memo[i] =  max(1 + h(n, validJumpPos, jump, arr, memo), h(n, i+1, jump, arr, memo));
}

int maximumMagnets1(int input1, int input2, int input3[]){
    // input 1 is size, input2 is minjump i need to take
    sort(input3, input3 + input1);
    vector<int> memo (input1, -1);
    return h(input1, 0, input2, input3, memo);
}

int maximumMagnets(int input1, int input2, int input3[]) {
    int n = input1;
    int jump = input2;
    sort(input3, input3 + n);
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        int* pos = lower_bound(input3 + i + 1, input3 + n, input3[i] + jump);
        int validJumpPos = pos - input3;
        int take = 1 + dp[validJumpPos];
        int skip = dp[i + 1];
        dp[i] = max(take, skip);
    }
    return dp[0];
}




int main(){
    int n = 10; // size of array
    int y = 4;
    int arr[n] = {1,5,6,1, 8, 3, 12, 2, 13, 7};
    cout<<maximumMagnets(n, y, arr);
}