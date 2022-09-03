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

    vl a(n+1);
    ll sm =0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sm+=a[i];
    }
    vl sp(n+1);
    ll cur = 0;
    for(int i=0;i<n;i++){
        if(cur<=sm-cur){
            sp[i] = (sm+i-1)/i;
        }else{
            sp[i] = (sm-cur+i-1)/i + (cur-sm+cur+i-2)/(i-1);
        }
        cur+=a[i];
    }

    int q;
    cin>>q;

    for(int i=0;i<q;i++){
        ll t;
        cin>>t;


        if(sp[n]>t){
            cout<<-1<<'\n';
            continue;
        }

        ll l = 1;
        ll r = n;

        while(l<r-1){
            ll m = (l+r)/2;
            
            if(sp[m]<=t){
                r = m;
            }else{
                l = m+1;
            }
        }

        if(sp[l]<=t){
            cout<<l<<'\n';
        }else{
            cout<<r<<'\n';
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

