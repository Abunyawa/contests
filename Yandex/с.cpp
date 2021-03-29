// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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





vi g[200100];
int sz = 0;
bool used[200100];

void dfs(int v){
    used[v]=true;
    sz++;
    for(auto x: g[v]){
        if(!used[x]){
            dfs(x);
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi szs;
    for(int i=0;i<n;i++){
        if(!used[i]){
            sz = 0;
            dfs(i);
            szs.pb(sz);
        }
    }
    sort(rall(szs));

    int k;
    cin>>k;
    vector<pair<int,int>> rooms(k);
    for(int i=0;i<k;i++){
        cin>>rooms[i].fi>>rooms[i].se;
    }

    sort(rall(rooms));

    int ptr = 0;
    for(auto x: szs){
        /*
        debug(rooms[ptr].se);
        debug(x);*/
        if(ptr>=k){
            cout<<0<<'\n';
            return;
        }
        if(x>rooms[ptr].fi){
            cout<<0<<'\n';
            return;
        }else{
            rooms[ptr].se--;
            if(rooms[ptr].se==0){
                ptr++;
            }
        }
    }

    cout<<1<<'\n';
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

