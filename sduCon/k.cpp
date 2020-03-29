#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int d[n][m];
    int dp[n][m];   
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>d[i][j];
            if(j==0){
                dp[i][j]=d[i][j];
            }
        }
       
    }

    for(int j=1;j<m;j++){
        for(int i=0;i<n;i++){
            //cout<<i<<' '<<j<<' '<<min(dp[max(i-1,0)][j-1],min(dp[i][j-1],dp[min(i+1,n-1)][j-1]))<<endl;
            dp[i][j] = max(min(dp[max(i-1,0)][j-1],min(dp[i][j-1],dp[min(i+1,n-1)][j-1])),d[i][j]);
        }
    }

    int ans=dp[0][m-1];
    //cout<<endl;
    for(int i=0;i<n;i++){
        if(dp[i][m-1]<ans){
            ans = dp[i][m-1];
        }
    }
    
   
    cout<<ans<<endl;
    

    
    return 0;
}

