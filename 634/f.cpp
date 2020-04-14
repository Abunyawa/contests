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
/*
abcccabc
*/
void solve(){
    int n,m;
    cin>>n>>m;
    int col[n*m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x;
            cin>>x;
            col[i*m+j] = (x=='0');
        }
    }
    int f[n*m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x;
            cin>>x;
            int to = -1;
            if(x=='U') to = (i-1)*m+j;
            if(x=='D') to = (i+1)*m+j;
            if(x=='L') to = i*m+j-1;
            if(x=='R') to = i*m+j+1;
            f[i*m+j] = to;
        }
    }
    int dp[n*m];
    int ndp[n*m];

    for(int i=0;i<n*m;i++){
        dp[i] = f[i];
    }
    for(int i=0;i<24;i++){
        for(int j=0;j<n*m;j++){
            ndp[j] =dp[dp[j]];
        }
        for(int j=0;j<n*m;j++){
            dp[j] = ndp[j];
        }
    }
    vector<int> tot(n*m,0);
    vector<int> totb(n*m,0);
    for(int i=0;i<n*m;i++){
        tot[dp[i]]++;
        totb[dp[i]] += col[i];
    }
    int tt = 0, tb = 0;
    for(int i=0;i<n*m;i++){
        if(tot[i]>0){
            tt++;
        }
        if(totb[i]>0){
            tb++;
        }
    }
    cout<<tt<<' '<<tb<<'\n';
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
