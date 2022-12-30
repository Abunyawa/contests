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
#define debug(x) cerr << #x << " = " << (x) << endl

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
    int q;
    cin>>q;
    map<ll,ll> ans;
    map<ll, bool> have;
    for(int i=0;i<q;i++){
        char op;
        cin>>op;
        ll x;
        cin>>x;

        if(op=='+'){
            have[x] = 1;
        }else{
            ll lastAns = ans[x];
            if(lastAns==0){
                lastAns=x;
            }
            while(have[lastAns]==1){
                lastAns+=x;
            }

            ans[x] = lastAns;

            cout<<lastAns<<'\n';
        }
    }
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

