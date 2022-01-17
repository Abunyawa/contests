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

vi g[500100];

void solve() {
    int q;
    cin>>q;

    vi arr;
    vector<pair<int,int>> sbs;

    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t==1){
            int x;
            cin>>x;
            arr.pb(x);
        }else{
            int x,y;
            cin>>x>>y;
            sbs.pb({x,y});
            arr.pb(-sbs.size());
        }
    }

    int n = arr.size();
    vi ans;
    map<int,int> m;
    for(int i=n-1;i>=0;i--){
        int cur = arr[i];

        if(cur<=0){
            cur*=-1;
            if(m[sbs[cur-1].se]!=0){
                m[sbs[cur-1].fi] = m[sbs[cur-1].se];
            }else{
                m[sbs[cur-1].fi] = sbs[cur-1].se;
            }
        }else{
            if(m[cur]==0){
                ans.pb(cur);
            }else{
                ans.pb(m[cur]);
            }
        }
    }
    reverse(all(ans));
    for(int x: ans){
        cout<<x<<' ';
    }
    cout<<'\n';
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

