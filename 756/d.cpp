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
int pre[200100];
int in[200100];
void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        g[i].clear();
        in[i] = 0;
        pre[i] = 0;
    }
    vi b(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x!=i){
            g[x].pb(i);
            in[i]++;
        }
        b[i] = x;
    }
    vi p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    ll cur = 1;

    vi ans(n+1,0);
    for(auto x: p){
        if(in[x]!=0){
            cout<<-1<<'\n';
            return;
        }else{
            if(b[x]==x){
                ans[x] = 0;
            }else{
                ans[x] = cur-pre[x];
                cur++;
            }

            for(auto to: g[x]){
                pre[to] = cur-1;
                in[to]--;
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';


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

