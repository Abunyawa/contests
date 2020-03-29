#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];

int main(){

    int n,m;
    cin>>n;
    int a[n+10];

    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i-1][0]=0;
    }
    cin>>m;
    int b[m+10];
    for(int i=1;i<=m;i++){
        cin>>b[i];
        dp[0][i-1]=0;

    }

    for(int i=1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(a[i]==b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }

        }
    }
    
    cout<<dp[n][m]<<endl;
}