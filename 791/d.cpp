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

vi gC[200100];

vi g[200100];
int ctr = 0;

ll a[200100];
int n,tt;
ll k;
int used[200100];
bool used1[200100];
int in[200100];
ll d[200100];
bool cyc;

void dfs(int v){
    used[v] = 1;

    for(int to: g[v]){
        if(used[to]==0){
            dfs(to);
        }else if(used[to]==1){
            cyc = true;
        }
    }

    used[v] = 2;
}

void dfsTop(int v){
    used1[v] = true;
    if(g[v].size()==0){
        d[v] = 0;
    }
    for(int to: g[v]){

        if(used1[to]==false){
            dfsTop(to);
        }

        d[v] = max(d[v], d[to]+1);
    }
}


bool calc(ll m){

    for(int i=1;i<=n;i++){
        g[i].clear();
        in[i] = 0;
        used[i] = 0;
        used1[i] = 0;
        d[i] = -1;
    }
    cyc = false;

    for(int i=1;i<=n;i++){
        if(a[i]<=m){
            for(int to: gC[i]){
                if(a[to]<=m){
                    g[i].pb(to);
                    in[to]++;
                }
            }
        }else{
            d[i] = -1e10;
            used[i] = 2;
            used1[i] = true;
        }
    }

    for(int i=1;i<=n;i++){
        if(used[i]==0){
            dfs(i);
        }
    }

    if(cyc){
        return true;
    }


    for(int i=1;i<=n;i++){
        if(in[i]==0 && used1[i]==false){
            dfsTop(i);
        }
    }
    

    for(int i=1;i<=n;i++){
        if(d[i]>=k-1){
            return true;
        }
    }

    return false;
}

void solve() {
    
    cin>>n>>tt>>k;


    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=0;i<tt;i++){
        int u,v;
        cin>>u>>v;


        gC[u].pb(v);
    }

    ll l = 1;
    ll r = 1e10;

    if(!calc(r)){
        cout<<-1<<'\n';
        return;
    }

    while(l<r-1){
        ll m = (l+r)/2LL;
        if(calc(m)){
            r = m;
        }else{
            l = m+1;
        }

    }

    if(!calc(l)){
        cout<<r<<'\n';
    }else{
        cout<<l<<'\n';
    }
    
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

