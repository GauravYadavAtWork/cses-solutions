#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

class Solution {
public:
    int solveNQueens(int n, vector<string>&grid) {
        int solutions = 0;
        vector<vector<int>> board (n,vector<int>(n,0));
        find(n,0,board,solutions, grid);
        return solutions;
    }
private:
    void find(int n,int row,vector<vector<int>>&board,int &solutions, vector<string>&grid){
        if(row==n){
            solutions++;
            return;
        }
        for(int i=0;i<n;i++){
            if(grid[row][i]=='.' && isvalid(board,row,i)){
                board[row][i]=1;
                find(n,row+1,board,solutions, grid);
                board[row][i]=0;
            }
        }
    }
    bool isvalid(vector<vector<int>>&board,int i, int j){
        for (int col = 0; col < board.size(); col++) {
            if (board[i][col] == 1) {
                return false;
            }
        }
        for (int row = 0; row < board.size(); row++) {
            if (board[row][j] == 1) {
                return false;
            }
        }
        int n = board.size();
        for (int x = 0; x < n; x++) {
            if (i+x < n && j+x < n && board[i+x][j+x] == 1) {
                return false;
            }
            if (i-x >= 0 && j-x >= 0 && board[i-x][j-x] == 1) {
                return false;
            }
            if (i+x < n && j-x >= 0 && board[i+x][j-x] == 1) {
                return false;
            }
            if (i-x >= 0 && j+x < n && board[i-x][j+x] == 1) {
                return false;
            }
        }
        return true;
    }
};


int main(){
    vector<string> grid (8);
    for(int i=0;i<8;i++){
        cin>>grid[i];
    }
    Solution s;
    cout<<s.solveNQueens(8, grid);
}