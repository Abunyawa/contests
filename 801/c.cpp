// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}



void solve() {
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1];


    int dp1[n+1][m+1];
    int dp2[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            dp1[i][j] = 0;
            dp2[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>a[i][j];
        }
    }


    if((n+m-1)%2==1){
        no();
        return;
    }


    dp1[1][1] = a[1][1];

    for(int i=2;i<=m;i++){
        dp1[1][i] = dp1[1][i-1];
        if(a[1][i]==1){
            dp1[1][i]++;
        }
    }

    for(int i=2;i<=n;i++){
        dp1[i][1] = dp1[i-1][1];
        if(a[i][1]==1){
            dp1[i][1]++;
        }
    }


    dp2[1][1] = a[1][1];

    for(int i=2;i<=m;i++){
        dp2[1][i] = dp2[1][i-1];
        if(a[1][i]==1){
            dp2[1][i]++;
        }
    }

    for(int i=2;i<=n;i++){
        dp2[i][1] = dp2[i-1][1];
        if(a[i][1]==1){
            dp2[i][1]++;
        }
    }

    
    
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            dp1[i][j] = min(dp1[i-1][j], dp1[i][j-1]);

            dp2[i][j] = max(dp2[i-1][j], dp2[i][j-1]);
            
        }
    }
    

    if((n+m-1)/2>=dp[n][m].first && (n+m-1)/2<=dp[n][m].second){
        yes();
    }else{
        no();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

