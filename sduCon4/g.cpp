#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    int a[n][m];
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>a[i][j];
            if(i!=0 && j!=0)
                a[i][j] += min(a[i-1][j],a[i][j-1]);
            else if(i!=0){
                a[i][j]+=a[i-1][j];
            }else if(j!=0){
                a[i][j]+=a[i][j-1];
            }
        }
    }

    cout<<a[n-1][m-1]<<endl;
}