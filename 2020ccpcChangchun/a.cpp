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
    vector<pii> sz;
    sz.pb({1,8});
    sz.pb({6,18});
    sz.pb({28,28});
    sz.pb({88,58});
    sz.pb({198,128});
    sz.pb({328,198});
    sz.pb({648,388});
    int ans  =0;
    for(int mask = 1;mask<(1<<8);mask++){
        int loca = 0;
        int locn = n;
        for(int i=0;i<7;i++){
            if(mask&(1<<i)){
                if(locn>=sz[i].fi){
                    loca+=sz[i].fi*10;
                    loca+=sz[i].se;
                    locn-=sz[i].fi;
                }
            }
        }
        loca+=locn*10;
        ans=max(ans,loca);
        
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

