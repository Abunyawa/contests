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
    int n;
    cin>>n;
    vi a(n);
    int dp[27][n];
    for(int i=0;i<27;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = 0;
        }
    }
    vector<int> cnt[27];
    vector<int> used(27,0);
    int mx =0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[a[i]][i] = 1;
        cnt[a[i]].pb(i);
        if(i!=0)
            for(int j=1;j<=26;j++){
                dp[j][i]+=dp[j][i-1];
                if(dp[j][i]>mx){
                    mx = dp[j][i];
                }
            }
    }
    for(int j=1;j<=26;j++){
        if(dp[j][0]>mx){
            mx = dp[j][0];
        }
    }
    for(int i=1;i<=26;i++){
        for(int j=0;j<cnt[i].size()/2;j++){
            for(int k=1;k<=26;k++){
                if(2*(j+1) + (dp[k][cnt[i][cnt[i].size()-1-j]-1]-dp[k][cnt[i][j]])>mx){
                    mx = 2*(j+1) + (dp[k][cnt[i][cnt[i].size()-1-j]-1]-dp[k][cnt[i][j]]);
                }
            }
        }
    }
    cout<<mx<<'\n';
    
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
