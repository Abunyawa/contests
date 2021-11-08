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
    int n;
    cin>>n;
    vi g[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            int x;cin>>x;
            g[i].pb(x);
        }
    }

    for(int d1 = 0;d1<5;d1++){
        for(int d2 = d1+1;d2<5;d2++){
            int c1 = 0;
            int c2 = 0;
            int cb = 0;
            for(int i=0;i<n;i++){
                if(g[i][d1]==1 && g[i][d2]==1){
                    cb++;
                }else if(g[i][d1]==1){
                    c1++;
                }else if(g[i][d2]==1){
                    c2++;
                }
            }

            if(c1<=n/2 && c2<=n/2 && c1+c2+cb==n){
                yes();
                return;
            }
        }
    }

    no();
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

