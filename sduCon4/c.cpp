#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int dp[1000000];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=4;i<=1000;i+=2){
        dp[i]=dp[i/2]+1;
        dp[i-1] = dp[i] + dp[(i-2)/2];
    }
    
    cout<<dp[n]<<endl;
}