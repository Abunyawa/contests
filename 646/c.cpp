#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define abu ios_base::sync_with_stdio(0)
#define said cin.tie(0)
using namespace std;
ll const MOD = 998244353;

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

ll fact(int n){
    ll ans = 1;
    for(int i=2;i<=n;i++){
        ans = (ans*i)%MOD;
    }

    return ans;
}

ll powM(int n, int x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return n%MOD;
    }

    if(x%2==0){
        ll a = powM(n,x/2);
        return (a*a)%MOD;
    }else{
        return (n*powM(n,x-1))%MOD;
    }
}

ll C(int n, int k){
    return (fact(n) * powM((fact(k)*fact(n-k))%MOD,MOD-2))%MOD;
}

ll A(int n, int k){
    return (fact(n) * powM(fact(n-k)%MOD,MOD-2))%MOD;
}

vi g[10000];
bool used[10000];
int cnt[10000];


void dfs(int v){
    used[v] = true;
    cnt[v] = 1;
    for(int i=0;i<g[v].size();i++){
        if(!used[g[v][i]]){
            dfs(g[v][i]);
            cnt[v] +=cnt[g[v][i]];
        }
    }
}

void solve(){
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        used[i] = false;
        cnt[i] = 0;
        g[i].clear();
    }
    vi  deg(n+1,0);  
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
        g[u].pb(v);
        g[v].pb(u);
    }
    if(deg[x]<=1){
        cout<<"Ayush\n";
    }else{
        dfs(x);
        if((cnt[x]-1)%2==0){
            cout<<"Ashish\n";
        }else{
            cout<<"Ayush\n";            
        }
    }
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
