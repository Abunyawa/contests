#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int dp[n+10];
    dp[n] = 1;
    for(int i=n-1;i>=0;i--){
        dp[i] = 0;
        for(int j=i+1;j<=min(i+3,n);j++){
            dp[i] += dp[j];
        }
    }
    cout<<dp[0]<<endl;
}