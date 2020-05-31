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

vi g[200100];
pair<int,int> cnt[200100];
int dp[200100];
int a[200100];
int b[200100];
int c[200100];
ll ans = 0;

void dfs(int v, int par){
    for(int i=0;i<g[v].size();i++){
        if(g[v][i]!=par){
            a[g[v][i]] = min(a[g[v][i]],a[v]);
            dfs(g[v][i],v);
        }
    }
}

void dfsCount(int v, int par){
    pii cur;
    if(b[v] == c[v]) cur = {0,0};
    else{
        if(b[v]==1) cur = {1,0};
        else cur = {0,1};
    }

    cnt[v] = cur;

    for(int i=0;i<g[v].size();i++){
        if(g[v][i]!=par){
            dfsCount(g[v][i],v);
            cnt[v].F+=cnt[g[v][i]].F;
            cnt[v].S+=cnt[g[v][i]].S;
        }
    }

    ans+=(ll)min(cnt[v].F,cnt[v].S)*2*a[v];
    int minp = (ll)min(cnt[v].F,cnt[v].S);
    cnt[v].F -=minp;
    cnt[v].S -=minp;
}


void solve(){
    int n;
    cin>>n;
    int ct1=0;
    int ct0=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        if(b[i]!=c[i]){
            if(b[i]==1){
                ct1++;
            }else{
                ct0++;
            }
        }
    } 
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }    
    if(ct0!=ct1){
        cout<<-1<<'\n';
    }else{
        dfs(1,1);
        dfsCount(1,1);
        cout<<ans<<'\n';
    }
}

int main(){
    abu;
    said;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
