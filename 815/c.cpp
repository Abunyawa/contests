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

    char a[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            a[i][j]-='0';
        }
    }

    int ans = 0;
    while(true){
        vi have(5,0);
        pii c[5];
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                int ctr = 0;
                if(a[i][j] == 1) ctr++;
                if(a[i][j+1] == 1) ctr++;
                if(a[i+1][j] == 1) ctr++;
                if(a[i+1][j+1] == 1) ctr++;
                have[ctr]++;
                c[ctr] = {i,j};
            }
        }

        bool done = false;
        for(int i=1;i<=4;i++){
            if(have[i]>0){
                //cout<<i<<' '<<c[i].fi<<' '<<c[i].se<<'\n';
                if(i==1) ans++;
                else ans+=2;
                a[c[i].fi][c[i].se] = 0;
                a[c[i].fi+1][c[i].se] = 0;
                a[c[i].fi][c[i].se+1] = 0;
                a[c[i].fi+1][c[i].se+1] = 0;
                done = true;
                break;
            }
        }

        if(!done) break;
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

