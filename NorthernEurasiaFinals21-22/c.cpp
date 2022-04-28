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
    vector<pii> a(3);
    cin>>a[0].fi>>a[0].se;
    cin>>a[1].fi>>a[1].se;
    cin>>a[2].fi>>a[2].se;

    sort(all(a));

    vector<pair<pii,pii>> ans;

    ans.pb({{a[1].fi, max(a[0].se, max(a[1].se, a[2].se))},{a[1].fi, min(a[0].se, min(a[1].se, a[2].se))}});

    ans.pb({a[0], {a[1].fi, a[0].se}});
    ans.pb({a[2], {a[1].fi, a[2].se}});
    

    cout<<ans.size()<<'\n';

    for(int i=0;i<ans.size();i++){
        cout<<ans[i].fi.fi<<' '<<ans[i].fi.se<<' '<<ans[i].se.fi<<' '<<ans[i].se.se<<'\n';
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

