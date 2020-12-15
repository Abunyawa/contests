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

void yes(){
    cout<<"YES"<<'\n';
}

void no(){
    cout<<"NO"<<'\n';
}

vi g[200100];
int ans =0;
int is[200100];

bool dfs(int v, int par){
    debug(v);
    if(!is[v]){
        bool ret = false;
        for(auto x: g[v]){
            if(x!=par){
                ret|=dfs(x,v);
            }
        }
        if(!ret){
            ans--;
        }
        return ret;
        
    }else{
        bool ret = true;
        for(auto x: g[v]){
            if(x!=par){
                dfs(x,v);
            }
        }
        return ret;
    }
}
void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int u,v,x;
        cin>>u>>v>>x;
        g[u].pb(v);
        g[v].pb(u);
    }  
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        is[x]++;
    }
    if(n==k){
        cout<<k<<'\n';
        return;
    }else{
        ans = n;
        for(int i=1;i<=n;i++){
            if(is[i]){
                dfs(i,0);
                break;
            }
        }
        cout<<ans<<'\n';
    }





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

