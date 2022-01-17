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
typedef pair<ll, ll> pll;
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

    vl k(n);
    vl h(n);

    for(int i=0;i<n;i++){
        cin>>k[i];
    }

    for(int i=0;i<n;i++){
        cin>>h[i];
    }

    vector<pll> p;

    for(int i=0;i<n;i++){
        ll l = k[i] - h[i] + 1;
        ll r = k[i];

        p.pb({l,r});   
    }

    vector<pll> good;
    for(int i = 0;i<n;i++){
        bool flag = true;
        for(int j = 0;j<n;j++){
            if(i==j) continue;

            if(p[i].fi>=p[j].fi && p[i].se<=p[j].se){
                flag = false;
            }
        }

        if(flag){
            good.pb(p[i]);
        }
    }


    sort(all(good));
    ll curL = 0;
    ll curR = 0;

    vector<pll> ans;
    for(int i=0;i<good.size();i++){
        if(curR < good[i].fi){
            ans.pb({curL,curR});
            curL = good[i].fi;
            curR = good[i].se;
        }else{
            curR = good[i].se;
        }
    }
    ans.pb({curL,curR});

    ll tot = 0;

    for(int i = 1;i<ans.size();i++){
        ll len = ans[i].se -ans[i].fi+1;
        ll need = (2+len-1) * len / 2;

        tot+=need;
    }

    cout<<tot<<'\n';
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

