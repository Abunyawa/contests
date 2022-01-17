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

int m[1000100];
int ctr[1000100];

void solve() {
    int n;
    cin>>n;
    vi a(n);
    int gc;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]++;
    }
    int ans = 0;
    

    for(int i=1e6;i>=1;i--){
        if(m[i]) continue;
        int gc = 0;
        for(int k = 2;k*i<=1e6;k++){
            if(m[i*k]) gc = __gcd(gc,k*i);
        }

        if(gc==i){
            ans++;
        }
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    //cin>>tt;

    while (tt--) {
        solve();
    }

    return 0;
}

