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
    ll m;
    cin>>n>>m;

    vector<pair<ll,ll>> a;

    for(int i=0;i<n;i++){
        ll x;
        cin>>x;

        ll ctr = 1;

        while(x%m==0){
            ctr*=m;
            x/=m;
        }

        a.pb({x,ctr});
        //cout<<x<<' '<<ctr<<'\n';
    }

    int k;
    cin>>k;
    //cout<<'\n';
    vector<pair<ll,ll>> b;
    for(int i=0;i<k;i++){
        ll x;
        cin>>x;

        ll ctr = 1;

        while(x%m==0){
            ctr*=m;
            x/=m;
        }

        b.pb({x,ctr});
        //cout<<x<<' '<<ctr<<'\n';
    }


    vector<pair<ll,ll>> an;
    vector<pair<ll,ll>> bn;

    for(int i=0;i<n;i++){
        if(an.size()==0){
            an.pb(a[i]);
        }else{
            if(an[an.size()-1].fi == a[i].fi){
                an[an.size()-1].se+=a[i].se;
            }else{
                an.pb(a[i]);
            }
        }
    }


    for(int i=0;i<k;i++){
        if(bn.size()==0){
            bn.pb(b[i]);
        }else{
            if(bn[bn.size()-1].fi == b[i].fi){
                bn[bn.size()-1].se+=b[i].se;
            }else{
                bn.pb(b[i]);
            }
        }
    }

    if(an.size()!=bn.size()){
        no();
        return;
    }

    for(int i=0;i<an.size();i++){
        //cout<<an[i].fi<<' '<<an[i].se<<' '<<bn[i].fi<<' '<<bn[i].se<<'\n';

        if(an[i]!=bn[i]){
            no();
            return;
        }
    }

    yes();

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

