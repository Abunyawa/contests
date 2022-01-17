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

vi g[200100];
int ans[200100];
map<pii,int> edg;


void dfs(int v, int par, int st){
    if(par!=-1){
        if(st%2==0){
            ans[edg[{v,par}]] = 2;
        }else{
            ans[edg[{v,par}]] = 3;
        }
    }

    for(int to: g[v]){
        if(to!=par){
            dfs(to,v,st+1);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        g[i].clear();
    }
    edg.clear();
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        edg[{u,v}] = i;
        edg[{v,u}] = i;
        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i=1;i<=n;i++){
        if(g[i].size()>2){
            cout<<-1<<'\n';
            return;
        }
    }


    for(int i=1;i<=n;i++){
        if(g[i].size()==1){
            dfs(i,-1,0);
            break;
        }
    }


    for(int i=0;i<n-1;i++){
        cout<<ans[i]<<' ';
    }

    cout<<'\n';
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

