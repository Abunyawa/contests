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
    map<pair<ll,ll>,ll> mo;
    map<ll,ll> ml;
    map<ll,ll> mr;
    ll mn = 1e10;
    ll mx = -1;
    for(int i=0;i<n;i++){
        ll l,r,c;
        cin>>l>>r>>c;

        mn = min(mn,l);
        mx = max(mx,r);

        if(l==mn && r==mx){
            if(mo[{l,r}]==0){
                mo[{l,r}] = c;
            }else{
                mo[{l,r}] = min(mo[{l,r}],c);
            }
        }

        if(ml[l] == 0){
            ml[l] = c;
        }else{
            ml[l] = min(ml[l],c);
        }

        if(mr[r] == 0){
            mr[r] = c;
        }else{
            mr[r] = min(mr[r],c);
        }

        if(mo[{mn,mx}]!=0){
            cout<<min(mo[{mn,mx}], ml[mn] + mr[mx])<<'\n';
        }else{
            cout<<ml[mn] + mr[mx]<<'\n';
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

