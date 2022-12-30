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
    int n, q;
    cin>>n>>q;

    vl a(n+1);
    ll sm = 0;
    ll xr = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sm+=a[i];
        xr^=a[i];
    }

    //debug(sm);
    //debug(xr);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        int ch = 0;
        while(l<r){
            ch = 0;
            if(l<r && (sm-a[l] - (xr^a[l])) >= sm-xr){
                //debug((sm-a[l] - xr^a[l]));
                sm-=a[l];
                xr^=a[l];
                l++;
                ch++;
            }

            if(l<r && (sm-a[r] - (xr^a[r])) >= sm-xr){
                sm-=a[r];
                xr^=a[r];
                r--;
                ch++;
            }

            if(ch==0){
                break;
            }
        }
        cout<<l<<' '<<r<<'\n';
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

