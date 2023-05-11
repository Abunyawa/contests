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
int n,m;
int dy[] = {1,0,-1,0};
int dx[] = {0,-1,0,1};
int gr[110][110];
vector<pii> g[110][110];
int in[110][110];
int used[110][110];
bool bad = false;
vector<pii> moves;

void solve() {
    int n;
    ll m;
    cin>>n>>m;
    vl c(n);
    vl d(n);

    ll ans = 0;
    for(int i=0;i<n-1;i++){
        cin>>c[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>d[i];
    }

    for(int i=1;i<n-1;i++){
        if(c[i]>c[i-1]){
            c[i] = c[i-1];
        }
    }
    ll pack_size = m;
    ll del = 0;
    for(int i=0;i<n-1;i++){
        ll tot_packs = (m+c[i]-1)/c[i];
        ans += d[i] + max(0LL,tot_packs-1-del);
        del += max(0LL,tot_packs-1-del);
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

