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
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

void solve(){
    int n;
    cin>>n;
    int d[n][n];
    bool dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char x;
            cin>>x;
            if(x=='1') d[i][j] = 1;
            else d[i][j] = 0;
            dp[i][j] = false;
        }
        dp[n-1][i] = true;
        dp[i][n-1] = true;
    }
    for(int i=0;i<n;i++){
        dp[n-1][i] = true;
        dp[i][n-1] = true;
    }
    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            if(d[i+1][j]==1 || d[i][j+1]==1){
                dp[i][j] = true;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d[i][j]==1 && dp[i][j]==false){
                no();
                return;
            }
        }
    }
    yes();
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
