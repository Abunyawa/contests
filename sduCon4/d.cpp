#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int dp[n+2][3];
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for(int i =2;i<=n;i++){
        dp[i][0] = dp[i-1][1]+dp[i-1][2];
        dp[i][1] = dp[i-1][1]+dp[i-1][2]+dp[i-1][0];
        dp[i][2] = dp[i-1][1]+dp[i-1][2]+dp[i-1][0];
    }
    
    cout<<dp[n][0]+dp[n][1]+dp[n][2]<<endl;
}