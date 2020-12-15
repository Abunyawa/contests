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
    char d[n][m];
    int ctr[n][m];
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>d[i][j];
            if(d[i][j]=='*'){
                ctr[i][j] = 1;
            }else{
                ctr[i][j] = 0;
            }        
        }
    }


    for(int i=n-1;i>=0;i--){
        for(int j = 0;j<m;j++){
            if(d[i][j] == '*'){
                if(i+1<n){
                    int ctr1 = 0;
                    if(j-1>=0){
                        if(d[i+1][j-1]=='*') ctr1++;
                    }
                    if(d[i+1][j]=='*') ctr1++;
                    
                    if(j+1<m){
                        if(d[i+1][j+1]=='*') ctr1++;
                    }

                    if(ctr1==3){
                        ctr[i][j] = min(ctr[i+1][j-1],min(ctr[i+1][j],ctr[i+1][j+1]));
                        ctr[i][j]++;
                    }

                }
            }
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            ans+=ctr[i][j];
        }
    }

    cout<<ans<<'\n';

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

