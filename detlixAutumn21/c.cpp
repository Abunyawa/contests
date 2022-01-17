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


vector<char> prime (1000100, true);


void solve() {
    int n,e;
    cin>>n>>e;
    
    vi a(n);

    vi rem[e];
    for(int i=0;i<n;i++){
        cin>>a[i];

        rem[i%e].pb(a[i]);
    }

    ll ans =0;

    for(int cur = 0;cur<e;cur++){
        int ctr =0;
        vi ind;
        ind.pb(-1);
        for(int i=0;i<rem[cur].size();i++){
            if(rem[cur][i]!=1){
                ind.pb(i);
            }
        }
        ind.pb(rem[cur].size());

        for(int i=1;i<ind.size()-1;i++){
            if(prime[rem[cur][ind[i]]]){
                ll left = ind[i]-ind[i-1]-1;
                ll right = ind[i+1]-ind[i]-1;

                ans += left*right + left + right;
            }
        }
    }


    cout<<ans<<'\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    prime[0] = prime[1] = false;
    for (int i=2; i<1000100; ++i)
        if (prime[i])
            if (i * 1ll * i < 1000100)
                for (int j=i*i; j<1000100; j+=i)
                    prime[j] = false;
    int tt = 1;
    cin>>tt;
    while (tt--) {
        solve();
    }

    return 0;
}

