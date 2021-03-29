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

ll num(int a, int b){
    ll ans = 0;
    if(min(a/2,b)>=2){
        ans+=min(a/2,b)-1;
    }

    if(min(b/2,a)>=2){
        ans+=min(b/2,a)-1;
    }
    return ans;
}


void solve() {
    int n,m;
    cin>>n>>m;
    int d[n+2][m+2];
    pair<int,int> curLU[n+2][m+2];
    pair<int,int> curRD[n+2][m+2];

    for(int i=0;i<=n;i++){
        curLU[i][0]= {0,0};
        curLU[i][m+1]= {0,0};
        curRD[i][0]= {0,0};
        curRD[i][m+1]= {0,0};

    }
    for(int i=0;i<=m;i++){
        curLU[0][i]= {0,0};
        curLU[n+1][i]= {0,0};
        curRD[0][i]= {0,0};
        curRD[n+1][i]= {0,0};

    }
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>d[i][j];
            if(d[i][j]==1){
                curLU[i][j].fi = curLU[i][j-1].fi+1;
                curLU[i][j].se = curLU[i-1][j].se+1;
            }else{
                curLU[i][j] = {0,0};
            }
        }
    }

    for(int i=n;i>0;i--){
        for(int j=m;j>0;j--){
            if(d[i][j] == 1){
                curRD[i][j].fi = curRD[i][j+1].fi+1;
                curRD[i][j].se = curRD[i+1][j].se+1;
            }else{
                curRD[i][j] = {0,0};
            }
        }
    }

    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            //cout<<curRD[i][j].fi<<", "<<curRD[i][j].se<<' ';
            
            if(d[i][j]==1){
                int a = curLU[i][j].fi;
                int b = curLU[i][j].se;
                int c = curRD[i][j].fi;
                int d = curRD[i][j].se;
                ans+=num(a,b);
                ans+=num(a,d);
                ans+=num(c,b);
                ans+=num(c,d);
                //cout<<ans<<'\n';
            }

            
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
    for(int i=1;i<=tt;i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}

