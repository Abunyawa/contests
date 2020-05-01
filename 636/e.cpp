#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}
vector<int> g[200100];
bool used[200100];
int path[200100];

void bfs(int v){
    used[v] = true;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int cr = q.front();
        q.pop();
        for(int i=0;i<g[cr].size();i++){
            if(!used[g[cr][i]]){
                used[g[cr][i]]= true;
                path[g[cr][i]] = cr;
                q.push(g[cr][i]);
            }
        }
    }

}

void solve(){
    int n,m,a,b,c;
    cin>>n>>m>>a>>b>>c;
    vl p(m);
    for(int i=0;i<=n;i++){
        path[i] = 0;
        used[i] = false;
        g[i].clear();
    }
    for(int i=0;i<m;i++){
        cin>>p[i];
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    path[a] = -1;
    bfs(a);
    int cr = b;
    map<pii,int> mp;
    while(cr!=-1){
        if(path[cr]!=-1){
            if(mp.find({path[cr],cr})!=mp.end())
                mp[{path[cr],cr}]++;
            else{
                mp[{cr,path[cr]}]++;
            }
        }
        cr = path[cr];
    }

    for(int i=0;i<=n;i++){
        path[i] = 0;
        used[i] = false;
    }
    path[b] = -1;
    bfs(b);
    cr = c;
    

    while(cr!=-1){
        if(path[cr]!=-1){
            if(mp.find({path[cr],cr})!=mp.end())
                mp[{path[cr],cr}]++;
            else{
                mp[{cr,path[cr]}]++;
            }
        }
        cr = path[cr];
    }
    vi ps;
    for(auto e: mp){
        ps.pb(e.S);
    }
    sort(all(ps));
    sort(all(p));
    ll ans = 0;
    int ptr = 0;
    for(int i = ps.size()-1;i>=0;i--){
        ans += ps[i]*p[ptr++]; 
    }
    cout<<ans<<'\n';
}

int main(){
    abu;
    said;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
