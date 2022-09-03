// chrono::system_clock::now().time_since_epoch().count()
#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

/*
3 2

1 5 {4 4}

2 4 {2 2}
*/

vi g[200100];
bool used[200100];
vi cycles;

void dfs(int v, int d){
    used[v] = true;

    for(int to: g[v]){
        if(used[to]){
            cycles.pb(d);
        }else{
            dfs(to,d+1);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    vi a(n+1);
    vi b(n+1); 
    cycles.clear();
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        g[i].clear();
        used[i] = false;
    }

    for(int i=1;i<=n;i++){
        cin>>b[i];
    }

    for(int i=1;i<=n;i++){
        g[a[i]].pb(b[i]);
    }


    for(int i=1;i<=n;i++){
        if(!used[i]){
            dfs(i,1);
        }
    }


    int l = 1;
    int r = n;
    ll ans = 0;

    for(int cyc: cycles){
        if(cyc==1){
            continue;
        }


        vi vals;
        if(cyc%2==1){
            cyc--;
        }
        for(int i = 0;i<cyc;i++){
            if(i%2==0){
                vals.pb(l++);
            }else{
                vals.pb(r--);
            }
        }   

        
        for(int i=0;i<cyc;i++){
            ans+=abs(vals[i] - vals[(i+1)%cyc]);
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

