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
    ll n;
    cin>>n;
    ll fix = sqrt(n);
    ll ans = 0;

    vector<pii> div;
    for(int i=2;i<=fix;i++){
        int ctr = 0;
        while(n%i==0){
            ctr++;
            n/=i;
        }

        if(ctr!=0){
            div.pb({i,ctr});
        }
    }

    if(n>1){
        div.pb({n,1});
    }


    while(true){
        ll add = 1;

        for(int i=0;i<div.size();i++){
            if(div[i].se>0){
                add*=div[i].fi;
                div[i].se--;
            }
        }

        if(add==1){
            break;
        }else{
            ans+=add;
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

