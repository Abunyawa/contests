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
bool used[200100];
bool used2[200100];
unordered_map<ll,int> col1;
unordered_map<ll,int> col2;

void bfs(int v){
    queue<int> q;

    q.push(v);
    used[v] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int to: g[cur]){
            if(!used[to]){
                col1[cur*(1e9) + to*1LL] = 1;
                col1[to*1e9+cur*1LL] = 1;

                q.push(to);
                used[to] = true;
            }
        }
    }
}

void dfs(int v){
    used2[v] = true;

    for(int to: g[v]){
        if(!used2[to]){
            col2[v*(1e9) + to*1LL] = 1;
            col2[to*1e9+v*1LL] = 1;

            dfs(to);
        }
    }
}


void solve() {
    int n, m;
    cin>>n>>m;
    col1.clear();
    col2.clear();
    for(int i=0;i<=n;i++){
        used[i] = false;
        used2[i] = false;
        g[i].clear();
    }

    vector<pii> ed;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        g[u].pb(v);
        g[v].pb(u);
        ed.pb({u,v});
    }

    if(m==n-1){
        for(int i=0;i<m;i++){
            cout<<1;
        }
        cout<<'\n';
        return;
    }else if(m<n+2){
        for(int i=1;i<=n;i++){
            if(!used[i]){
                bfs(i);
            }
        }



        for(int i=0;i<m;i++){
            cout<<col1[ed[i].fi*1e9+ed[i].se*1LL];
        }

        cout<<'\n';
    }else{
        for(int i=1;i<=n;i++){
            if(!used2[i]){
                dfs(i);
            }
        }

        set<int> st1;
        for(int i=0;i<m;i++){
            if(col2[ed[i].fi*1e9+ed[i].se*1LL]==0){
                st1.insert(ed[i].fi);
                st1.insert(ed[i].se);
            }
        }
        if(st1.size()!=3){
            for(int i=0;i<m;i++){
                cout<<col2[ed[i].fi*1e9+ed[i].se*1LL];
            }

            cout<<'\n';
            return;
        }

        for(int i=1;i<=n;i++){
            if(!used[i]){
                bfs(i);
            }
        }
       
        
        for(int i=0;i<m;i++){
            cout<<col1[ed[i].fi*1e9+ed[i].se*1LL];
        }

        cout<<'\n';
        

        
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

