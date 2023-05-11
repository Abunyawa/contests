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
    int n,k,d,w;
    cin>>n>>k>>d>>w;
    vector<pii> t(n);

    for(int i=0;i<n;i++){
        cin>>t[i].fi;
        t[i].se = t[i].fi+w;
    }

    int st = 0;
    int cur = 0;
    int ans =0;

    for(int i=0;i<n;i++){
        if(cur==k){
            ans++;
            cur = 0;
            st = i;
        }
        if(t[i].fi<=t[st].se+d){
            cur++;
        }else{
            ans++;
            cur = 1;
            st = i;
        }
    }
    if(cur!=0){
        ans++;
        cur = 0;
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

