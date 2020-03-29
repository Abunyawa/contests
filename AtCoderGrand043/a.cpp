#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;

void yes(){
    cout<<"YES"<<endl;
}

void no(){
    cout<<"NO"<<endl;
}

void solve(){
    int h,w;
    cin>>h>>w;
    int d[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char a;
            cin>>a;
            if(a=='#'){
                d[i][j]=0;
            }else{
                d[i][j] = 1;
            }
        }
    }
    int dp[h][w];
    dp[0][0] = d[0][0]==0?1:0;
    for(int i=1;i<h;i++){
        if(d[i][0]==0){
            dp[i][0] = dp[i-1][0]+1;
        }else{
            dp[i][0] = dp[i-1][0];
        }
        for(int k = 0;k<=i;k++){
            if(dp[i][0]-dp[k][0]+1 == i-k+1 && d[k][0]==0 && d[i][0]==0){
                dp[i][0] = min(dp[k][0],dp[i][0]);
            }
            
        }
    }
    for(int i=1;i<w;i++){
        if(d[0][i]==0){
            dp[0][i] = dp[0][i-1]+1;
        }else{
            dp[0][i] = dp[0][i-1];
        }
        for(int k = 0;k<=i;k++){
            if(dp[0][i]-dp[0][k]+1 == i-k+1 && d[0][k]==0 && d[0][i]==0){
                dp[0][i] = min(dp[0][k],dp[0][i]);
            }
            
        }
    }
    for(int i=1;i<h;i++){
        for(int j=1;j<w;j++){
            if(d[i][j]==0){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
            }else{
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
            }
            for(int k = 0;k<=i;k++){
                for(int z = 0;z<=j;z++){
                    if(dp[i][j]-dp[k][z]+1 == i-k+1+j-z && d[k][z]==0 && d[i][j]==0){
                        dp[i][j] = min(dp[k][z],dp[i][j]);
                    }
                }
            }
        }
    }
    
    cout<<dp[h-1][w-1]<<endl;
}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
