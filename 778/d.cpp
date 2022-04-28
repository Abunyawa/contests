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
const ll MOD = 998244353;

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



vector<int> g[200100];
bool used[200100];
map<pair<int,int>,pair<ll,ll>> m;
int ctr = 0;

void bfs(int v){

    queue<pii> q;

    q.push({v,1});
    used[v] = true;

    while(!q.empty()){
        ctr++;
        int cur = q.front().first;
        int par = q.front().second;
        //cout<<cur<<endl;
        q.pop();
        if(par!=1 && cur !=1){
            pair<ll,ll> hp = m[{1,par}];
            pair<ll,ll> pc = m[{par,cur}];

            ll nhp = hp.first * pc.first;
            ll npc = hp.second * pc.second;

            ll gcd = __gcd(nhp, npc);
            nhp /= gcd;
            npc /= gcd;

            m[{1,cur}] = {nhp, npc};
            m[{cur,1}] = {npc, nhp};
        }

        for(int to: g[cur]){
            if(!used[to]){
                used[to] = true;
                q.push({to, cur});
            }
        }
    }
}



void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        g[i].clear();
        used[i] = false;
    }
    m.clear();
    ctr = 0;
    for(int i=0;i<n-1;i++){
        int u,v;
        ll x,y;

        cin>>u>>v>>x>>y;
        ll gcd = __gcd(x,y);

        x/=gcd;
        y/=gcd;
        m[{u,v}] = {x,y};
        m[{v,u}] = {y,x};
        g[u].pb(v);
        g[v].pb(u);
    }

    bfs(1);
    if(ctr!=n){
        cout<<ctr<<endl;
        assert(0);
    }
    vector<ll> div;

    for(int i=2;i<=n;i++){
        div.pb(m[{1,i}].first);
    }
    sort(all(div));
    ll nm = div[div.size()-1];
    for(int i=div.size()-2;i>=0;i--){
        ll gcd = __gcd(nm,div[i]);
        ll miss = div[i]/gcd;
        nm=(nm*miss)%MOD;
    }
    ll frs = nm;
    /*
    ll gcd = div[0];
    for(int i=1;i<div.size();i++){
        gcd = __gcd(gcd,div[i]);
    }
    
    for(int i=0;i<div.size();i++){
        //frs = (frs*div[i])%MOD;
        frs = ((div[i]*frs)%MOD * powM(__gcd(frs,div[i]), MOD-2))%MOD;
    }
    //frs = (frs * powM(gcd,MOD-2))%MOD;

    */
    ll ans = frs;

    for(int i=2;i<=n;i++){
        pair<ll,ll> tp = m[{1,i}];

        ans += ((frs*powM(tp.first,MOD-2)%MOD)*tp.second)%MOD;

        if(ans>MOD){
            ans-=MOD;
        }
    }

    cout<<ans<<'\n';
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

