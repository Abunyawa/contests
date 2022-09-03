// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
    vector<pii> h;
    vector<pii> v;
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>d[i][j];
            if(d[i][j]=='B'){
                h.pb({j,i});
                v.pb({i,j});
            }
        }
    }

    sort(all(h));

    sort(all(v));
    

    int lx = h[0].second, ly = h[0].first;

    int rx = h[h.size()-1].second, ry = h[h.size()-1].first;

    int uy = v[0].second, ux = v[0].first;

    int dy = v[v.size()-1].second, dx = v[v.size()-1].first;


    vector<array<int,5>> ar;

    ar.pb({abs(lx-rx)+abs(ly-ry), lx,ly,rx,ry});
    ar.pb({abs(lx-ux)+abs(ly-uy), lx,ly,ux,uy});
    ar.pb({abs(lx-dx)+abs(ly-dy), lx,ly,dx,dy});

    ar.pb({abs(rx-ux)+abs(ry-uy), rx,ry,ux,uy});
    ar.pb({abs(rx-dx)+abs(ry-dy), rx,ry,dx,dy});

    ar.pb({abs(ux-dx)+abs(uy-dy), ux,uy,dx,dy});

    int ans = 1e9;
    int x,y;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int d = 0;

            d = max(d, abs(i-lx)+abs(j-ly));

            d = max(d, abs(i-rx)+abs(j-ry));

            d = max(d, abs(i-ux)+abs(j-uy));

            d = max(d, abs(i-dx)+abs(j-dy));

            if(d<ans){
                ans = d;
                x = i;
                y = j;
            }
        }
    }

    cout<<x+1<<' '<<y+1<<'\n';

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

