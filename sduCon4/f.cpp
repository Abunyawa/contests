#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,k;
    cin>>n>>k;
    int dp[k+1];
    dp[0] =0;
    dp[1] = n;

    for(int i=2;i<=k;i++){
        dp[i]=(dp[i-1]*(n-(i-1)))/i;

    }

    cout<<dp[k]<<endl;
}