#include<bits/stdc++.h>
using namespace std;

void h(int n, int start, int intermediate, int dest){
    if(n==1){
        cout<<start<<" "<<dest<<"\n";
        return;
    }
    cout<<start<<" "<<dest<<"\n";
    h(n-1,start, dest, intermediate);
    cout<<dest<<" "<<start<<"\n";
}

int main(){
    int n;
    cin>>n;
    h(n, 1, 2, 3);
}