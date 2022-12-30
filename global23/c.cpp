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



void solve() {
    int n;
    cin>>n;

    vi a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<pii> dif;

    for(int i=0;i<n-1;i++){
        if(a[i+1]<a[i]){
            dif.pb({a[i]-a[i+1], i+1});
        }
    }

    sort(all(dif));

    vi ans(n+1,1);

    int p = 0;
    int cur = 1;
    while(p<dif.size()){
        //debug(dif[p].fi);
        ans[cur] = dif[p].se + 1;
        dif[p].fi-=cur;
        //debug(dif[p].fi);
        cur++;
        if(dif[p].fi<=0){
            p++;
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
