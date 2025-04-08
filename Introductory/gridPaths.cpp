#include<bits/stdc++.h>
using namespace std;

int pathsCount = 0;

void count(string &path, int i, vector<vector<bool>>&vis, int x, int y){
    if(i==path.size() && x==6 && y==0){
        pathsCount++;
        return;
    }
    if(x<0 || y<0 || x>=7 || y>=7 || vis[x][y] || vis[6][0]) return;
    vis[x][y] = true;
    if(path[i]=='?'){ // go 4 directionally
        count(path, i+1, vis, x+1, y);
        count(path, i+1, vis, x-1, y);
        count(path, i+1, vis, x, y+1);
        count(path, i+1, vis, x, y-1);
    }else if(path[i]=='R'){ // go right
        count(path, i+1, vis, x, y+1);
    }else if(path[i]=='L'){ // go left
        count(path, i+1, vis, x, y-1);
    }else if(path[i]=='U'){ // go up
        count(path, i+1, vis, x-1, y);
    }else{ // go down
        count(path, i+1, vis, x+1, y);
    }
    vis[x][y] = false;
}


int main(){
    string path = "??????R??????U??????????????????????????LD????D?";
    vector<vector<bool>> vis(7, vector<bool>(7,false));
    count(path, 0, vis, 0, 0);
    cout<<pathsCount;
}