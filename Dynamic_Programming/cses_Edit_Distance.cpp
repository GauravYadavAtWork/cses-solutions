#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

class Solution {
vector<vector<int>> memo;
public:
    int minDistance(string word1, string word2) {
        memo = vector<vector<int>>(word1.size(), vector<int>(word2.size(),-1));
        return h(word1, 0, word2, 0);
    }
private:
    int h(string&word1, int i, string&word2, int j){
        if(i==word1.size() && j==word2.size()) return 0;
        if(i==word1.size() || j==word2.size()) return word1.size()-i + word2.size() -j;
        if(memo[i][j]!=-1) return memo[i][j];
        int result = INT_MAX;
        if(word1[i]==word2[j]) result = h(word1, i+1, word2, j+1);
        result = min(result, 1 + h(word1, i, word2, j+1)); // insert a char
        result = min(result, 1 + h(word1, i+1, word2, j)); // remove char
        result = min(result, 1 + h(word1, i+1, word2, j+1)); // replace a char
        return memo[i][j] = result;
    }
};

int main(){
    string a, b;
    cin>>a>>b;
    Solution s;
    cout<<s.minDistance(a, b);
}
