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
    int n,q;
    cin>>n>>q;

    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<pair<int,ll>> qr(q);
    vector<vi> tour(n+1);
    for(int i=0;i<q;i++){
        cin>>qr[i].fi>>qr[i].se;
        qr[i].fi--;
        if(qr[i].se<n){
            tour[qr[i].se].pb(qr[i].fi);
        }
    }

    map<pair<int,ll>,ll> ans;
    
    int ptr = 0;
    int cur = 1;
    vi wins(n+1,0);

    for(int i=1;i<n;i++){
        if(a[i]<a[ptr]){
            wins[ptr]++;
        }else if(a[i]>a[ptr]){
            ptr = i;
            wins[ptr]++;
        }

        if(tour[cur].size()>0){
            for(int j = 0;j<tour[cur].size();j++){
                ans[{tour[cur][j], cur}] = wins[tour[cur][j]];
            }
        }
        cur++;
    }
/*
    for(int i=0;i<n;i++){
        cout<<wins[i]<<' ';
    }

    cout<<'\n';*/

    for(int i=0;i<q;i++){
        if(qr[i].se<n){
            cout<<ans[{qr[i].fi,qr[i].se}]<<'\n';
        }else{
            if(a[qr[i].fi]==n){
                cout<<wins[qr[i].fi]+(qr[i].se-n+1LL)<<'\n';
            }else{
                cout<<wins[qr[i].fi]<<'\n';
            }
        }
    }
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

