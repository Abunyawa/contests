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
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
 
void yes(){
    cout<<"YES"<<'\n';
}
 
void no(){
    cout<<"NO"<<'\n';
}
int n, k;
array<int, 27> d[300100];
vi g[300100];
int par[300100];
bool dead[300100];
int ctr = 2;
int dp[300100];
bool endH[300100];
set<pair<int,int>> ver;
 
void add(string s){
    int n = s.length();
    int cur = 1;
    for(int i=0;i<n;i++){
        if(d[cur][s[i]-'a']==0){
            d[cur][s[i]-'a']=ctr++;
        }
 
        cur = d[cur][s[i]-'a'];
         
    }
}
 
void build(int v){
    for(int i=0;i<27;i++){
        if(d[v][i]!=0){
            g[v].pb(d[v][i]);
            par[d[v][i]] = v;
        }
    }
 
    for(int to: g[v]){
        build(to);
    }
}
 
void dfsPrint(int v){
    cout<<v<<' '<<par[v]<<' '<<dp[v]<<endl;
    for(int to: g[v]){
        dfsPrint(to);
         
    }
}
void dfs(int v){
    if(g[v].size()==0){
        dp[v] = 1;
    }
    for(int to: g[v]){
        dfs(to);
        dp[v] += dp[to];
         
    }
     
    if(dp[v]<=k){
        g[v].clear();
    }
     
}
 
void dfs1(int v){
    if(g[v].size()==0){
        if(dp[v]<=k){
            ver.insert({-dp[v], v});
        }
    }
    for(int to: g[v]){
        dfs1(to);
    }
}
 
void delChild(int v){
    dead[v] = true;
    if(g[v].size()==0){
        ver.erase({-dp[v], v});
    }
    for(int to: g[v]){
        if(!dead[to]){
            delChild(to);
        }
    }
    g[v].clear();
}
 
void del(int v){
    int prev = v;
    int st = par[v];
    int nxt = -1;
    while(st!=1){
        dp[st] -= dp[v];
        if(dp[st]<=k){
            nxt = st;
        }
        st = par[st];
    }
    dp[st] -= dp[v];
    if(dp[st]<=k){
        nxt = st;
    }
    dead[v] = true;
    if(nxt!=-1){
        for(int to: g[nxt]){
            if(!dead[to]){
                delChild(to);
            }
        }
        ver.insert({-dp[nxt], nxt});
    }
}
 
 
void solve() {
    cin>>n>>k;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
 
        add(s+"{");
    }
    build(1);
    dfs(1);
    dfs1(1);
    //dfsPrint(1);
    int ans = 0;
    while(!ver.empty()){
        int curW = ver.begin()->first;
        int cur = ver.begin()->second;
        ver.erase({curW,cur});
         
        ans++;
        if(cur>1){
            del(cur);
        }else{
            break;
        }
    }
 
    cout<<ans<<'\n';
 
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