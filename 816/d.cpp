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

vector<pii> g[200100];

void solve() {
    int n,q;
    cin>>n>>q;

    vl a(n, (1LL<<31)-1);
    vi st;

    vl ans(n,0);

    for(int i=0;i<q;i++){
        int u,v,x;
        cin>>u>>v>>x;
        u--;v--;
        if(u==v){
            ans[u] = x;
            continue;
        }
        a[u]&=x;
        a[v]&=x;

        g[min(u,v)].pb({max(u,v),x});
    }    
       

    for(int i=0;i<n;i++){
        if(a[i]==(1LL<<31)-1){
            a[i] = 0;
            continue;
        }


        for(pii to: g[i]){
            ans[i]|=(to.se^a[to.fi]);
        }

        for(pii to: g[i]){
            ans[to.fi]|=(to.se^ans[i]);
        }
    }


    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }

    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    //cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

