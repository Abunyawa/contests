// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}



void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    ll d[n][k];
    for(int i =0;i<n;i++){
        for(int j = 0;j<k;j++){
            cin>>d[i][j];
        }
    }
    ll ans = 0;
    vector<int> inds(m);
    for(int i=0;i<(1<<(k+1));i++){
        if(__builtin_popcount(i)==m){
            vector<pll> sum(k, {0,0});
            for(int j = 0;j<k;j++){
                if((1<<j)&i){
                    ll mx = 0;
                    int ind = -1;
                    for(int row = 0;row<n;row++){
                        if(d[row][j]>mx){
                            mx = d[row][j];
                            ind = row;
                        }
                    }
                    sum[j] = {mx,ind};
                    for(int row = 0;row<n;row++){
                        if(d[row][j]==mx){
                            for(int col = 0;col<k;col++){
                                if(!((1<<col)&i)){
                                    if(d[row][col]>sum[col].fi){
                                        sum[col] = {d[row][col],-1};
                                    }
                                }
                            }
                        }
                    }
                }
            }
            ll loc = 0;
            for(int cur = 0;cur<k;cur++){
                loc+=sum[cur].fi;
            }

            if(loc>ans){
                ans = loc;
                inds.clear();
                for(int cur = 0;cur<k;cur++){
                    if(sum[cur].se>=0) inds.pb(sum[cur].se);
                }
            }
        }
    }

    cout<<ans<<'\n';
    for(int i=0;i<m;i++){
        cout<<inds[i]<<' ';
    }
    cout<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    
    while (tt--) {
        solve();
    }

    return 0;
}

